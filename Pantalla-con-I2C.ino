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