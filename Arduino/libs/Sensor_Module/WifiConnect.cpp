#include <Arduino.h>
#include <WifiConnect.h>

//SoftwareSerial esp8266Serial = SoftwareSerial(2, 3);


WifiConnect::WifiConnect(int wifi_pintx, wifi_pinrx){
  ESP8266 wifi = ESP8266(esp8266Serial);
  esp8266Serial.begin(115200);
  wifi.begin();
  wifi.setTimeout(3000);
  
}
String WifiConnect::connecting(){
    
  if(getStatus(wifi.joinAP(SSID, PASS))=="ESP8266_COMMAND_OK"){
        Serial.println("wifi joinAP ok");
  }
  //tcp/ip connect
  if(getStatus(wifi.connect(ESP8266_PROTOCOL_TCP, DST_IP, 80))){
       Serial.println("wifi connect ok");
  }
    
  //tcp/ip send
  if(getStatus(wifi.send("GET / HTTP/1.0\r\n\r\n"))){
      Serial.println("wifi send ok");
  }
}
String WifiConnect::getStatus(ESP8266CommandStatus status)
{
    switch (status) {
    case ESP8266_COMMAND_INVALID:
        return "INVALID";
        break;
 
    case ESP8266_COMMAND_TIMEOUT:
        return "TIMEOUT";
        break;
 
    case ESP8266_COMMAND_OK:
        return "OK";
        break;
 
    case ESP8266_COMMAND_NO_CHANGE:
        return "NO CHANGE";
        break;
 
    case ESP8266_COMMAND_ERROR:
        return "ERROR";
        break;
 
    case ESP8266_COMMAND_NO_LINK:
        return "NO LINK";
        break;
 
    case ESP8266_COMMAND_TOO_LONG:
        return "TOO LONG";
        break;
 
    case ESP8266_COMMAND_FAIL:
        return "FAIL";
        break;
 
    default:
        return "UNKNOWN COMMAND STATUS";
        break;
    }
}

String WifiConnect::getStatus(bool status)
{
    if (status)
        return "OK";
 
    return "KO";
}

String WifiConnect::getRole(ESP8266Role role)
{
    switch (role) {
    case ESP8266_ROLE_CLIENT:
        return "CLIENT";
        break;
 
    case ESP8266_ROLE_SERVER:
        return "SERVER";
        break;
 
    default:
        return "UNKNOWN ROLE";
        break;
    }
}
String WifiConnect::getProtocol(ESP8266Protocol protocol)
{
    switch (protocol) {
    case ESP8266_PROTOCOL_TCP:
        return "TCP";
        break;
 
    case ESP8266_PROTOCOL_UDP:
        return "UDP";
        break;
 
    default:
        return "UNKNOWN PROTOCOL";
        break;
    }
}