import pandas as pd
import numpy as np
import tensorflow as tf
import emlearn # convierte a C el modelo de keras para el arduino
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense
from sklearn.model_selection import train_test_split

# Lee el csv y asigna nombres para encabezados
df = pd.read_csv('datos_serial.csv', header=None, names=['R', 'G', 'B', 'fruta'])

# Separa entradas y etiquetas, convierte la tabla en una matriz de Numpy
# Cambia el tipo de dato a float de 32 bits ya que así se realizan los entrenamientos
X = df[['R', 'G', 'B']].values.astype('float32')

# La manza a es 0 y la pera es 1
y = df['fruta'].values

# Divide el csv para entrenamiento en un 80-20 y lo revuelve para así no usar datos uno detrás de otro siempre
X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.2, random_state=42, stratify=y
)

# Modelo de red neuronal con 3 capas, una con 3 entradas (R, G, B) y otra densa de 2 perceptrones, uno por fruta y otro para la nada
model = Sequential([
    Dense(8, input_shape=(3,), activation='relu'),
    Dense(3, activation='softmax')
])

# Configuración de la red neuronal
model.compile(
    optimizer='adam',
    loss='sparse_categorical_crossentropy',
    metrics=['accuracy']
)

# Se muestra en la terminal un resumen de la red creada
model.summary()

# Entrenamiento de 25 épocas junto con validación de los datos
# Cada 32 datos calcula el error promedio y vuelve a calcular los pesos
historial = model.fit(
    X_train, y_train,
    epochs=25,
    batch_size=32,
    # Cada vez que se acaba una época, la red es evaluada con el 20% de los datos reservados sin ajustar los pesos
    validation_data=(X_test, y_test)
)

# Evalua el entrenamiento con el 20% de datos que se reservaron mostrando la precisión durante la prueba
loss, accuracy = model.evaluate(X_test, y_test, verbose=0)
print(f"\nPrecisión en prueba: {accuracy * 100:.2f}%")

# Prueba con un dato
nombres_frutas = ['MANZANA', 'PERA', 'SIN FRUTA']
muestra = np.array([[41, 22, 2]], dtype='float32')
prediccion = model.predict(muestra, verbose=0)
indice_ganador = np.argmax(prediccion)
print(f"Predicción para [41, 22, 2]: {nombres_frutas[indice_ganador]} ({prediccion[0]})")

# Guardar modelo
model.save('modelo_frutas.keras')


# Convierte el modelo de Keras a código C
cmodel = emlearn.convert(model, method='inline')

# Guarda el archivo para arduino
cmodel.save(file='modelo_frutas.h', name='modelo_frutas')
