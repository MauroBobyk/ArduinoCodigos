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
const int sensorPin = 9;
int LED=10;
void setup()
{
   digitalWrite(LED,LOW);
   Serial.begin(9600);
}

void loop()
{
   bool state = digitalRead(sensorPin);

   //mandar mensaje a puerto serie en función del valor leido
   if (state == HIGH)
   {
      Serial.println("Detección");   
      //aquí se ejecutarían las acciones
    digitalWrite(LED,HIGH);
   }
   delay(1000);
}
