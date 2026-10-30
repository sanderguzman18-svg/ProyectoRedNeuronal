import pandas as pd
import numpy as np

df=pd.read_csv("./datos.csv")
print(df)
X=df.iloc[:,0:3].values
print(X)
y=df.iloc[:,3].values
print(y)

##########

# Inicialización de pesos y bias
np.random.seed(42)
w = np.random.randn(3)
b = np.random.randn()

# Función de activación escalón
def step(z):
    return 1 if z >= 0 else 0

# Entrenamiento (regla del perceptrón)
lr = 0.1
for epoch in range(20):
    for xi, yi in zip(X, y):
        z = np.dot(xi, w) + b
        y_pred = step(z)
        error = yi - y_pred
        w += lr * error * xi
        b += lr * error

print("Pesos:", w, "Bias:", b)

# Predicciones
for xi in X:
    z = np.dot(xi, w) + b
    print(xi, "->", step(z))