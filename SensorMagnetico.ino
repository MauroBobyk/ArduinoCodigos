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
