#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

// Configuración del LCD I2C (usa 0x27 o 0x3F según tu módulo)
LiquidCrystal_I2C lcd(0x27, 16, 2);  // Dirección, columnas, filas

// Configuración del DHT22
#define DHTPIN 2           // Pin donde está conectado el DHT22
#define DHTTYPE DHT22      // Tipo de sensor
DHT dht(DHTPIN, DHTTYPE);

// Variables para temperatura y humedad
float temperatura = 0;
float humedad = 0;

// Símbolo personalizado de grado °
byte grado[8] = {
  B01100,
  B10010,
  B10010,
  B01100,
  B00000,
  B00000,
  B00000,
  B00000
};

void setup() {
  Serial.begin(9600);
  
  // Inicializar LCD
  lcd.init();
  lcd.backlight();
  lcd.createChar(0, grado);  // Crear carácter personalizado
  
  // Inicializar DHT22
  dht.begin();
  
  // Mensaje inicial
  lcd.setCursor(0, 0);
  lcd.print("Iniciando...");
  delay(2000);
  lcd.clear();
}

void loop() {
  // Leer datos del sensor
  leerDHT();
  
  // Mostrar en LCD
  mostrarEnLCD();
  
  // Mostrar en Monitor Serial (opcional)
  mostrarEnSerial();
  
  // Esperar 2 segundos entre lecturas
  delay(2000);
}

void leerDHT() {
  // Leer humedad
  humedad = dht.readHumidity();
  // Leer temperatura en Celsius
  temperatura = dht.readTemperature();
  
  // Verificar si la lectura falló
  if (isnan(humedad) || isnan(temperatura)) {
    Serial.println("Error leyendo el sensor DHT22!");
    humedad = 0;
    temperatura = 0;
  }
}

void mostrarEnLCD() {
  lcd.clear();
  
  // Mostrar temperatura
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperatura, 1);  // 1 decimal
  lcd.write(0);  // Símbolo de grado
  lcd.print("C");
  
  // Mostrar humedad
  lcd.setCursor(0, 1);
  lcd.print("Humedad: ");
  lcd.print(humedad, 1);  // 1 decimal
  lcd.print("%");
}

void mostrarEnSerial() {
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.print("°C \t");
  Serial.print("Humedad: ");
  Serial.print(humedad);
  Serial.println("%");
}
