/*
  Copyright (C) 2026, Mauro Bobyk.

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <https://gnu.org>.
*/
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
