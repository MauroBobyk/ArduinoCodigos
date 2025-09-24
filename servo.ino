#include <Servo.h>

Servo miServo;  // Crear objeto servo
int pinServo = 9;  // Pin donde está conectado

void setup() {
  miServo.attach(pinServo);  // Inicializar servo
}

void loop() {
  // Mover a 0 grados
  miServo.write(0);
  delay(1000);
  
  // Mover a 90 grados
  miServo.write(90);
  delay(1000);
  
  // Mover a 180 grados
  miServo.write(180);
  delay(1000);
}
