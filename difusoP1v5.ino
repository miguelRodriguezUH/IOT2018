#include <PubSubClient.h>
#include <stdlib.h>
#include <ESP8266WiFi.h>
#include <stdlib.h>
#include <ESP8266WiFi.h>
const char* ssid = "*****";
const char* password = "*******";
const char* mqtt_server = "broker.mqttdashboard.com";

char pub_str[100];


WiFiClient espClient;
PubSubClient client(espClient);


#define echoPin D7 // Echo Pin
#define trigPin D6 // Trigger Pin


long duration; // Duration used to calculate distance
float distance;
float solAnt = 0;
int ldrMedida;

int datos = 0;
#include "Controlador_difuso.h"
Controlador_difuso controlador;

void setup() {
  Serial.begin(115200);
  delay(1000);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(A0, INPUT);

  Serial.println(ssid);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print("-");
  }

  Serial.println();
  Serial.println("WiFi Connected");
  Serial.println("WiFi got IP");
  Serial.println();
  Serial.println(WiFi.localIP());
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
  reconnect();

}

void loop() {
  float sol;
  /* if (Serial.available() > 0) {
     if (datos == 0) {
       distance = Serial.parseFloat();
       datos = 1;
       Serial.println("Dato Recibido");
     } else if (datos == 1) {
       ldrMedida = Serial.parseFloat();
       datos = 2;
       Serial.println("Dato Recibido");
     }
     if (datos == 2) {
       datos = 0;
       Serial.print("Distancia: "); Serial.print(distance); Serial.print(" LDR: "); Serial.print(ldrMedida);
       sol = controlador.Controlador(distance, ldrMedida);

       if (!client.connected()) {
         reconnect();
       }
       if (sol == 1) {
         Serial.println(" Salida: Suelo");
         strcpy(pub_str, "Suelo");
       } else if (sol == 2) {
         Serial.println(" Salida: Bicicleta");
         strcpy(pub_str, "Bicileta");
       } else if (sol == 3) {
         Serial.println(" Salida: Coche");
         strcpy(pub_str, "Coche");
       } else {
         Serial.println(" Salida: Camion");
         strcpy(pub_str, "Camion");
       }
       client.publish("iiot2018/detectado/plaza1", pub_str);
       delay(1000);
       client.loop();
     }

    }//*/

  leerUltraSonido();
  leerLDR();//*/

  Serial.print("medida Ultrasonido: "); Serial.print(distance);
  Serial.print(" medida LDR: "); Serial.print(ldrMedida); ///*

  sol = controlador.Controlador(distance, ldrMedida);
  if (!client.connected()) {
    reconnect();
  }
  if (sol == 1) {
    Serial.println(" Salida: Suelo");
    strcpy(pub_str, "Suelo");
  } else if (sol == 2) {
    Serial.println(" Salida: Bicicleta");
    strcpy(pub_str, "Bicileta");
  } else if (sol == 3) {
    Serial.println(" Salida: Coche");
    strcpy(pub_str, "Coche");
  } else {
    Serial.println(" Salida: Camion");
    strcpy(pub_str, "Camion");
  }
  if (sol != solAnt) {
    solAnt = sol;
    client.publish("iiot2018/detectado/plaza1", pub_str);
  }

  delay(1000);
  client.loop();//*/
}
void leerUltraSonido() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  //Calculate the distance (in cm) based on the speed of sound.
  distance = duration / 58.2;
}
void leerLDR() {
  ldrMedida = analogRead(A0);
}

void callback(char* topic, byte* payload, unsigned int length)
{

  Serial.print("Message arrived : ");
  Serial.print(topic);
}

void reconnect()
{

  while (!client.connected()) {
    Serial.println("Attempting MQTT connection");
    if (client.connect("clientId-FANySPqlvv"))
    {
      Serial.println("Connected");
      Serial.print("subscribed!");
    }
    else
    {
      Serial.print("Failed, rc = ");
      Serial.print(client.state());
      Serial.println("Waiting for 5 seconds to try again");
      delay(5000);
    }
  }
}
