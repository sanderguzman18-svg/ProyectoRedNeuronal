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

model.compile(
    optimizer='adam',
    loss='categorical_crossentropy',
    metrics=['accuracy'])

model.summary()
