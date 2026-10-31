import csv
import serial

# --- Configuración ---
PUERTO = "COM8"  # En Windows (ej. COM3). En Linux/Mac usa algo como '/dev/ttyUSB0'
BAUDIOS = 9600
ARCHIVO_CSV = "datos_serial.csv"

print(f"Conectando a {PUERTO} a {BAUDIOS} baudios...")

try:
  # Abrimos el puerto serial
  with serial.Serial(PUERTO, BAUDIOS, timeout=1) as ser:
    print("Conectado con éxito. Presiona Ctrl+C para salir.")

    # Abrimos el archivo CSV en modo 'a' (append) para añadir al final
    with open(ARCHIVO_CSV, mode="a", newline="", encoding="utf-8") as f:
      writer = csv.writer(f)

      while True:
        # Lee una línea completa desde el puerto serial
        linea_breathe = ser.readline()

        if linea_breathe:
          # Decodifica los bytes a texto y elimina espacios/saltos de línea al inicio/final
          dato_limpio = linea_breathe.decode("utf-8").strip()

          if dato_limpio:
            print(f"Recibido: {dato_limpio}")

            # OPCIÓN A: Si el dispositivo envía los datos separados por comas (ej: "25,60,1013")
            valores = dato_limpio.split(",")

            # Escribe los valores al final del archivo CSV
            writer.writerow(valores)
            f.flush()  # Fuerza el guardado inmediato en el disco

except serial.SerialException:
  print(f"Error: No se pudo abrir el puerto {PUERTO}. Verifica la conexión.")
except KeyboardInterrupt:
  print("\nPrograma detenido por el usuario.")

    
    
    