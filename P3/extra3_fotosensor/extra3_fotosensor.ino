// --- DEFINICIÓN DE PINES ---
const int pinLDR = A0;   // Pin analógico para leer el sensor de luz
const int pinLed = 9;    // Pin digital para el LED de la farola

// --- CONFIGURACIÓN ---
// Si la luz baja de este número, encenderemos el LED.
// (Tendrás que ajustar este número viendo el Monitor Serie de Tinkercad)
const int umbralOscuridad = 1000; 

void setup() {
  pinMode(pinLed, OUTPUT);
  // Los pines analógicos no necesitan pinMode para entrada, pero iniciamos el Monitor Serie
  Serial.begin(9600); 
}

void loop() {
  // 1. Leer el valor del sensor (de 0 a 1023)
  int nivelLuz = analogRead(pinLDR);
  
  // 2. Imprimir el valor en el Monitor Serie para poder verlo
  Serial.print("Nivel de luz actual: ");
  Serial.println(nivelLuz);
  
  // 3. Lógica del detector
  if (nivelLuz < umbralOscuridad) {
    // Si hay muy poca luz (es de noche), encendemos el LED
    digitalWrite(pinLed, HIGH);
  } else {
    // Si hay suficiente luz (es de día), apagamos el LED
    digitalWrite(pinLed, LOW);
  }
  
  // Pequeña pausa para no saturar el Monitor Serie
  delay(100); 
}
