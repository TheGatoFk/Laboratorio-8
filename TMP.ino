const int pinSensorTemperatura = A0; // Pin analógico donde está conectado el sensor de temperatura

void setup() {
  Serial.begin(9600); // Iniciar comunicación serial a 9600 baudios
}

void loop() {
  // Leer el valor analógico del sensor de temperatura
  int lecturaSensor = analogRead(pinSensorTemperatura);
  
  // Convertir el valor leído a temperatura en grados Celsius
  float temperaturaCelsius = convertirLecturaATemperatura(lecturaSensor);
  
  // Imprimir la temperatura en el monitor serial
  Serial.print("Temperatura: ");
  Serial.print(temperaturaCelsius);
  Serial.println(" °C");
  
  delay(1000); // Esperar 1 segundo antes de realizar la siguiente lectura
}

float convertirLecturaATemperatura(int lectura) {
  // Coeficientes para la conversión lineal
  float a = 0.1; // Ajusta este valor según tu sensor
  float b = -50; // Ajusta este valor según tu sensor
  
  // Conversión lineal de la lectura a temperatura
  float temperatura = a * lectura + b;
  
  return temperatura;
}
