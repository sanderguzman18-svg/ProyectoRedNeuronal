import numpy as np

X = np.array([[0,0],[0,1],[1,0],[1,1]])
y = np.array([[0],[1],[1],[0]])

np.random.seed(42)

# Pesos capa oculta (2 entradas -> 2 neuronas)
W1 = np.random.randn(2, 2)
b1 = np.zeros((1, 2))

# Pesos capa salida (2 neuronas -> 1 salida)
W2 = np.random.randn(2, 1)
b2 = np.zeros((1, 1))

def sigmoid(z):
    return 1 / (1 + np.exp(-z))

def sigmoid_deriv(a):  # a = sigmoid(z)
    return a * (1 - a)

lr = 0.5

for epoch in range(10000):
    # ---- Forward ----
    z1 = X @ W1 + b1
    a1 = sigmoid(z1)          # capa oculta
    z2 = a1 @ W2 + b2
    a2 = sigmoid(z2)          # salida

    # ---- Backprop ----
    error_salida = a2 - y                      # (4,1)
    dW2 = a1.T @ (error_salida * sigmoid_deriv(a2))
    db2 = np.sum(error_salida * sigmoid_deriv(a2), axis=0, keepdims=True)

    error_oculta = (error_salida * sigmoid_deriv(a2)) @ W2.T   # (4,2)
    dW1 = X.T @ (error_oculta * sigmoid_deriv(a1))
    db1 = np.sum(error_oculta * sigmoid_deriv(a1), axis=0, keepdims=True)

    # ---- Update ----
    W1 -= lr * dW1
    b1 -= lr * db1
    W2 -= lr * dW2
    b2 -= lr * db2

# ---- Resultados ----
z1 = X @ W1 + b1
a1 = sigmoid(z1)
a2 = sigmoid(a1 @ W2 + b2)

print("Predicciones XOR:")
for xi, pi, yi in zip(X, a2, y):
    print(f"{xi} -> {pi[0]:.3f}  (esperado {yi[0]})")