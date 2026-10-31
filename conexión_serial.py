import time
import serial
escalon = lambda x: 0 if x < 0 else 1
encoding = 'utf-8'
# Iniciando conexión serial
arduinoPort = serial.Serial('/dev/ttyUSB0', 9600, timeout=1)
# Retardo para establecer la conexión serial
time.sleep(.8) 
for i in range(20):    
    getSerialValue = arduinoPort.readline()
    cadena=getSerialValue.decode(encoding)
    print(cadena)