/*
 *  ESP8266 JSON Decode of server response
 *  -Manoj R. Thkuar
 *  https://circuits4you.com
 */

#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>
#include <md5.h>

const char* wifiName = "Khan - 2G";
const char* wifiPass = "fatima2005";

//Web Server address to read/write from 
const char *host = "http://192.168.0.210:8080/json";//"http://arduinojson.org/example.json";

MD5Builder _md5;

String md5(String str) {
  _md5.begin();
  _md5.add(String(str));
  _md5.calculate();
  return _md5.toString();
}


void setup() {
  
  Serial.begin(115200);
  delay(10);
  Serial.println();
  
  Serial.print("Connecting to ");
  Serial.println(wifiName);

  WiFi.begin(wifiName, wifiPass);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());   //You can get IP address assigned to ESP
}

void loop() {
  HTTPClient http;    //Declare object of class HTTPClient

  WiFiClient client;

  Serial.print("Request Link:");
  Serial.println(host);
  
  http.begin(client,host);//,(uint16_t)8080);     //Specify POST destination

  http.addHeader("Content-Type", "application/json");
  
  DynamicJsonDocument message(2048);
  message["cmd"] = "login";
  String msgString;
  serializeJson(message,msgString);

  //int httpCode = 1;
  int postCode = http.POST(msgString);
  Serial.println(msgString);
  
  String payload = http.getString();    //Get the response payload from server
  //int httpCode = http.GET();            //Send the request

  Serial.print("Response Code:"); //200 is OK
  //Serial.println(httpCode);   //Print HTTP return code
  Serial.println(postCode);


  //payload = http.getString();

  Serial.print("Returned data from Server:");
  Serial.println(payload);    //Print request response payload
  
  if(postCode == 200)
  {
    http.end();  //Close connection
    // Allocate JsonBuffer
    // Use arduinojson.org/assistant to compute the capacity.
    const size_t capacity = JSON_OBJECT_SIZE(3) + JSON_ARRAY_SIZE(2) + 192;
    DynamicJsonDocument doc(capacity);
  
   // Parse JSON object
    //JsonObject root = doc.parseObject(payload);
    auto error = deserializeJson(doc, payload);
    if (error) {
      Serial.println(F("Parsing failed!"));
      return;
    }

    const char* result = doc["result"]; // "fail"
    const char* session = doc["session"]; // "0e885c285f45408520193ece11f8419f"

    bool data_auth_exempt = doc["data"]["auth-exempt"]; // false
    const char* data_reason = doc["data"]["reason"]; // "missing response"

    Serial.print("Request Link:");
    Serial.println(host);


    message.clear();
    message["cmd"] = "login";
    message["session"] = session;
    Serial.println("GOTHERE\n");
    char temp[80] ;
    sprintf(temp,"shahmir:%s:khan",session);
    message["response"] = md5(temp);
    String msgString;
    serializeJson(message,msgString);
    // Decode JSON/Extract values
    //Serial.println(F("Response:"));
    //Serial.println(doc["result"].as<const char*>());
    //Serial.println(doc["session"].as<const char*>());
    //Serial.println(doc["data"][0].as<const char*>());
    //Serial.println(doc["data"][1].as<const char*>());
    http.begin(client,host);//,(uint16_t)8080);     //Specify POST destination

    http.addHeader("Content-Type", "application/json");
    postCode = http.POST(msgString);
    Serial.println(msgString);
  
    String payload = http.getString();    //Get the response payload from server
    //int httpCode = http.GET();            //Send the request

    Serial.print("Response Code:"); //200 is OK
    //Serial.println(httpCode);   //Print HTTP return code
    Serial.println(postCode);


    //payload = http.getString();

    Serial.print("Returned data from Server:");
    Serial.println(payload);    //Print request response payload
    http.end();

    message.clear();
    message["cmd"] = "camlist";
    message["session"] = session;

    serializeJson(message,msgString);



    http.begin(client,host);//,(uint16_t)8080);     //Specify POST destination

    http.addHeader("Content-Type", "application/json");
    postCode = http.POST(msgString);
    Serial.println(msgString);
  
    payload = http.getString();    //Get the response payload from server
    //int httpCode = http.GET();            //Send the request

    Serial.print("Response Code:"); //200 is OK
    //Serial.println(httpCode);   //Print HTTP return code
    Serial.println(postCode);


    //payload = http.getString();

    Serial.print("Returned data from Server:");
    Serial.println(payload);    //Print request response payload
    http.end();


  }
  else
  {
    http.end();  //Close connection
    Serial.println("Error in response");
  }

  http.end();  //Close connection
  
  delay(5000);  //GET Data at every 5 seconds
}