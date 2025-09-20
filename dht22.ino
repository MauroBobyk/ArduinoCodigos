#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

// Configuración del sensor DHT22
#define DHTPIN 2
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

// Configuración de la LCD I2C
// Dirección I2C común: 0x27 o 0x3F
// Tamaño de la pantalla: 16 columnas x 2 filas
LiquidCrystal_I2C lcd(0x27, 16, 2); 

// Variables para control de actualización
unsigned long ultimaActualizacion = 0;
const unsigned long intervaloActualizacion = 2000; // 2 segundos

// Símbolo personalizado de grado °
byte gradoSimbolo[8] = {
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
  // Inicializar comunicación serial
  Serial.begin(9600);
  Serial.println("Iniciando sistema DHT22 + LCD I2C...");

  // Inicializar sensor DHT
  dht.begin();

  // Inicializar LCD I2C
  lcd.init();
  lcd.backlight();
  
  // Crear símbolo personalizado de grado
  lcd.createChar(0, gradoSimbolo);
  
  // Mensaje inicial
  lcd.setCursor(0, 0);
  lcd.print("Iniciando...");
  lcd.setCursor(0, 1);
  lcd.print("DHT22 + LCD I2C");
  
  delay(2000);
  lcd.clear();
}

void loop() {
  unsigned long tiempoActual = millis();

  // Actualizar cada 2 segundos (mínimo para DHT22)
  if (tiempoActual - ultimaActualizacion >= intervaloActualizacion) {
    ultimaActualizacion = tiempoActual;
    
    // Leer datos del sensor
    float humedad = dht.readHumidity();
    float temperatura = dht.readTemperature();

    // Verificar si la lectura fue exitosa
    if (isnan(humedad) || isnan(temperatura)) {
      mostrarError();
      return;
    }

    // Mostrar datos en LCD
    mostrarDatosLCD(humedad, temperatura);
    
    // También mostrar por serial (opcional)
    mostrarDatosSerial(humedad, temperatura);
  }
}

void mostrarDatosLCD(float humedad, float temperatura) {
  lcd.clear();
  
  // Primera fila: Humedad
  lcd.setCursor(0, 0);
  lcd.print("H:");
  lcd.print(humedad, 1); // 1 decimal
  lcd.print("%");
  
  // Segunda fila: Temperatura
  lcd.setCursor(0, 1);
  lcd.print("T:");
  lcd.print(temperatura, 1); // 1 decimal
  lcd.write(0); // Símbolo de grado
  lcd.print("C");
  
  // Espacio adicional para mejor formato
  lcd.setCursor(11, 0);
  lcd.print("DHT22");
}

void mostrarDatosSerial(float humedad, float temperatura) {
  Serial.print("Humedad: ");
  Serial.print(humedad);
  Serial.print(" %\t");
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" °C");
}

void mostrarError() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Error sensor!");
  lcd.setCursor(0, 1);
  lcd.print("Verificar conexion");
  
  Serial.println("Error: No se pudo leer el sensor DHT22");
}
