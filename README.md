# ArduinoBlueIris
Arduino API to integrate with Blue Iris Security Software JSON API

Not all functionality of the JSON API can be implemented onto the Arduino due to hardware limitations

But all useful functionality will be implemented to help DIYers better control their video security experience.

Blue Iris JSON API is documented here:
https://blueirissoftware.com/BlueIris.PDF

## How to use
```
#include "ArduinoBlueIris.h

// replace 192.168.0.69:8080 with your Blue Iris server ip and port... KEEP the /json at the end

void setup(){
 BlueIris blueIris (SSID,SSIDpass,"http://192.168.0.69:8080/json",blueIrisUsername,blueIrisPassword);
}

void loop(){
 blueIris.update();
 
 if(blueIris.getCam(1).isNoSignal()){
  //Camera 1 is disconnected :O  :'(
 }
 
 if(digitalRead(7) == HIGH){
 
  blueIris.getCam("FrontDoor").trigger();
  //or
  blueIris.trigger("FrontDoor");
  
  blueIris.getCam("FrontDoor").ptz("left");
  blueIris.getCam("FrontDoor").ptz("zoomIn");
  blueIris.getCam("FrontDoor").ptz("zoomOut");
  blueIris.getCam("FrontDoor").ptz("up");
  
  //or
  
  blueIris.ptz("FrontDoor","left");
  
  
  
 }
 
 
}
```

## Completed tasks:
 - ✅Login and authenticate MD5 🥳️You do not need to expose your Blue Iris server, disable secure authentication, or create exclusions for the Arduino. The code is able to successfully authenticate through the normal handshake protocal and login to Blue Iris without any changes to the main server settings.
 - ✅Implement "ptz" JSON command to move any Camera in array
 - ✅Implement "camlist" JSON command to generate abstracted array of type Camera
 - ✅Link camera flags extracted from server's JSON response to each Camera to check isNoSignal, isMotion, isTriggered, isRecording, FPS, etc...
 - ✅Implement a BlueIris.update() method to update status of server and Cameras

### 😜🥳️✅😎😎API V0.1 BETA WILL RELEASE ON JUNE 20th !
Most major features have been finished, but not pushed to the repo yet as I have to figure out license and stress testing. As well as finishing exams... Wish me luck!

## Todo:

 - ~~Implement "camlist" JSON command to generate abstracted array of type Camera~~
 - ~~Link camera flags extracted from server's JSON response to each Camera to check isNoSignal, isMotion, isTriggered, isRecording, FPS, etc...~~
 - ~~Implement a BlueIris.update() method to update status of server and Cameras~~
 - ~~Implement "trigger" JSON command to activate recording on any Camera in array~~
 - ~~Implement "ptz" JSON command to move any Camera in array~~
 - Implement "logout" JSON command


JSON commands pertaining to window management are currently not a priority and will possibly not be implemented. If your use case involves using an Arduino to to wirelessly switch between cameras on your screen, and select different cameras to be full screen. Then please open an issue and I will add window management to the priority list as well.
