#include <Servo.h>

Servo miServo;  // Crear objeto servo
int pinServo = 9;  // Pin donde conectamos el servo

void setup() {
  miServo.attach(pinServo);  // Conectar servo al pin
    // iniciar a 0 grados
  miServo.write(0);
 
}

void loop() {
//mueve de 0 a 180°
  miServo.write(0);
  delay(1000);

  // Mover a 180 grados
  miServo.write(180);
  delay(1000);
}
