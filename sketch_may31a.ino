// Valores de resistencia del divisor de tensión
const float R1 = 10000.0;  // Resistencia en ohmios
const float R2 = 2500.0;   // Resistencia en ohmios

// Pin de salida para el reloj
const int pinCLK = 9;

void setup() {
  pinMode(pinCLK, OUTPUT); // Configurar el pin de salida como salida digital
  Serial.begin(9600); // Inicializar la comunicación serial
}

void loop() {
  int sensorValue = analogRead(A0); // Leer el valor analógico en A0
  float voltage = sensorValue * (5.0 / 1023.0); // Calcular el voltaje en base al valor leído
  float inputVoltage = voltage * (R1 + R2) / R2; // Calcular el voltaje de entrada real
  float dutyCycle = 5.0 / (5.0 + inputVoltage); // Calcular el ciclo de trabajo
  //Serial.print("Voltaje de entrada: ");
  //Serial.print(inputVoltage);
  //Serial.println(" V");
  
  //Serial.print("Ciclo de trabajo: ");
  //Serial.print(dutyCycle);
  //Serial.println(" %");
  float pwmValue = dutyCycle * 255; // Convertir el ciclo de trabajo a un valor PWM (0-255)
  
  analogWrite(pinCLK, pwmValue); // Establecer el valor PWM en el pin de salida
  
}
