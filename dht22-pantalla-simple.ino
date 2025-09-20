#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal_I2C lcd(0x27, 16, 2);

// Variables para el display
int pantallaActual = 0;
const int totalPantallas = 2;
unsigned long ultimoCambio = 0;
const unsigned long intervaloCambio = 5000; // Cambiar pantalla cada 5s

// Símbolos personalizados
byte gradoSimbolo[8] = {
  B01100, B10010, B10010, B01100, B00000, B00000, B00000, B00000
};

byte gotaAgua[8] = {
  B00100, B00100, B01010, B01010, B10001, B10001, B10001, B01110
};

void setup() {
  Serial.begin(9600);
  dht.begin();
  
  lcd.init();
  lcd.backlight();
  lcd.createChar(0, gradoSimbolo);
  lcd.createChar(1, gotaAgua);
  
  mensajeInicial();
}

void loop() {
  static unsigned long ultimaLectura = 0;
  
  if (millis() - ultimaLectura >= 2000) {
    ultimaLectura = millis();
    actualizarDatos();
  }
  
  if (millis() - ultimoCambio >= intervaloCambio) {
    ultimoCambio = millis();
    pantallaActual = (pantallaActual + 1) % totalPantallas;
    actualizarDisplay();
  }
}

void actualizarDatos() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  
  if (!isnan(h) && !isnan(t)) {
    mostrarPantalla(h, t);
  } else {
    mostrarError();
  }
}

void mostrarPantalla(float humedad, float temperatura) {
  lcd.clear();
  
  switch(pantallaActual) {
    case 0:
      // Pantalla principal
      lcd.setCursor(0, 0);
      lcd.write(1); // Símbolo de gota
      lcd.print(" ");
      lcd.print(humedad, 1);
      lcd.print("%");
      
      lcd.setCursor(0, 1);
      lcd.print("T: ");
      lcd.print(temperatura, 1);
      lcd.write(0); // Símbolo de grado
      lcd.print("C");
      break;
      
    case 1:
      // Pantalla extendida
      lcd.setCursor(0, 0);
      lcd.print("DHT22 Sensor");
      
      lcd.setCursor(0, 1);
      lcd.print("H:");
      lcd.print(humedad, 0);
      lcd.print("% T:");
      lcd.print(temperatura, 0);
      lcd.write(0);
      lcd.print("C");
      break;
  }
}

void mensajeInicial() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("  Sensor DHT22");
  lcd.setCursor(0, 1);
  lcd.print("  con LCD I2C");
  delay(2000);
  lcd.clear();
}

void mostrarError() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Error de sensor");
  lcd.setCursor(0, 1);
  lcd.print("Verificar cableado");
}
