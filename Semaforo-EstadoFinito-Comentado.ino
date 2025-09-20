// Máquina de Estados Finito para control de semáforo
enum SemaforoEstados {
  ROJO,       // Estado ROJO (valor 0)
  AMARILLO,   // Estado AMARILLO (valor 1)
  VERDE       // Estado VERDE (valor 2)
};

SemaforoEstados estadoSemaforo = ROJO;  // Estado inicial del semáforo
unsigned long tiempoCambio = 0;         // Almacena el tiempo del último cambio de estado

void setup() {
  // Configurar pines como salidas para los LEDs
  pinMode(9, OUTPUT);   // LED Rojo
  pinMode(10, OUTPUT);  // LED Amarillo
  pinMode(11, OUTPUT);  // LED Verde
}

void loop() {
  // Máquina de estados - evalúa el estado actual
  switch(estadoSemaforo) {
    
    case ROJO:
      // Acciones del estado ROJO
      digitalWrite(9, HIGH);    // Encender LED rojo
      digitalWrite(10, LOW);    // Apagar LED amarillo
      digitalWrite(11, LOW);    // Apagar LED verde
      
      // Transición: ROJO -> VERDE después de 5 segundos
      if (millis() - tiempoCambio > 5000) {
        estadoSemaforo = VERDE;       // Cambiar al estado VERDE
        tiempoCambio = millis();      // Actualizar tiempo de cambio
      }
      break;
      
    case VERDE:
      // Acciones del estado VERDE
      digitalWrite(9, LOW);     // Apagar LED rojo
      digitalWrite(10, LOW);    // Apagar LED amarillo
      digitalWrite(11, HIGH);   // Encender LED verde
      
      // Transición: VERDE -> AMARILLO después de 4 segundos
      if (millis() - tiempoCambio > 4000) {
        estadoSemaforo = AMARILLO;    // Cambiar al estado AMARILLO
        tiempoCambio = millis();      // Actualizar tiempo de cambio
      }
      break;
      
    case AMARILLO:
      // Acciones del estado AMARILLO
      digitalWrite(9, LOW);     // Apagar LED rojo
      digitalWrite(10, HIGH);   // Encender LED amarillo
      digitalWrite(11, LOW);    // Apagar LED verde
      
      // Transición: AMARILLO -> ROJO después de 2 segundos
      if (millis() - tiempoCambio > 2000) {
        estadoSemaforo = ROJO;        // Cambiar al estado ROJO (reiniciar ciclo)
        tiempoCambio = millis();      // Actualizar tiempo de cambio
      }
      break;
  }
  
  // Pequeña pausa para evitar saturación del procesador
  delay(10);
}