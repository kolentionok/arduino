#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT22
#define PIN_RELAY 3

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  pinMode(PIN_RELAY, OUTPUT); // Пин реле - выход
  digitalWrite(PIN_RELAY, HIGH); // Выключаем реле, посылаем высокий сигнал
  Serial.begin(9600);
  Serial.println("Проверка, подключен ли датчик...");
  dht.begin();
}

void loop() {
float h = dht.readHumidity(); // влажность
float t = dht.readTemperature(); //температура
if (isnan(t) || isnan(h)) {
Serial.println("кожаный, датчик мне подключи"); // отказоустойчивость при потери датчика
}
else {
Serial.print("Humidity: ");
Serial.print(h);
Serial.print(" %\t");
Serial.print("Temperature: ");
Serial.print(t);
Serial.println(" *C");  
}
 
  if(h > 70 || t > 40) {
      digitalWrite(PIN_RELAY, LOW); // Включаем реле - посылаем низкий уровень сигнала. 
  } 
  if (h < 51 && t < 35){
   digitalWrite(PIN_RELAY, HIGH); // Выключаем реле
    }
  }
