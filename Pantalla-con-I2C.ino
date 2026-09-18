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
#include <Wire.h>
//buscar la libreria "LiquidCrystal_I2C de frank brabander "
#include <LiquidCrystal_I2C.h>

// Dirección I2C 0x27 o 0x3F
LiquidCrystal_I2C lcd(0x27, 16, 2);  // Dirección 0x27, LCD 16x2
// en caso de que no muestre nada en pantalla, ajustar el potenciometro
void setup() {
  lcd.init();        
  lcd.backlight();  
 
  lcd.setCursor(0, 0);        
  lcd.print("Hola Mundo!"); //fESTO INICIALIZA LA FILA 1    
  lcd.setCursor(0, 1);          
  lcd.print("FILA 2");    //ESTO INICIALIZA LA FILA 2

  //SI QUIEREN PONER TEXTO PROPIO O MOSTRAR UNA VARIABLE, PONERLO DENTRO DE VOID LOOP LCD.PRINT("")
 
}
void loop() {

}
