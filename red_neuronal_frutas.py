import keras
import tensorflow as tf
from tensorflow.keras import layers
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense

# Se define un modelo secuencial, es decir, los daos fluyen en este orden
model = Sequential(
    [
     #Se genera una capa densa, cada neurona se conecta con todas las entradas
     Dense(3, input_shape=(3,), activation ='softmax')
     ])

#Genera la configuración del modelo (funcion de aprendizaje o como saca los pesos y bias, perdida, y parametros a observar)
model.compile(
    optimizer='adam',
    loss='categorical_crossentropy',
    metrics=['accuracy'])

#Muestra un resumen del modelo en la terminal (cantidad de parametros como bias y pesos, además de cantidad de capas, neuronas, etc)
model.summary()
