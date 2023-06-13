# ArduinoBlueIris
Arduino API to integrate with Blue Iris Security Software JSON API

Not all functionality of the JSON API can be implemented onto the Arduino due to hardware limitations

But all useful functionality will be implemented to help DIYers better control their video security experience.

Blue Iris JSON API is documented here:
https://blueirissoftware.com/BlueIris.PDF

## How to use

### Dependencies
 - ArduinoJson V6
 - HTTPClient
 - WiFiClient
 - ESP8266 MD5

All dependencies are #included in the ArduinoBlueIris.h file

### Examples
```
#include "ArduinoBlueIris.h"

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

### BlueIris Class
```
//Create a BlueIris client instance called "blueIrisClient"

const char* SSID = "myWifiName";
const char* SSIDpass = "myWifiPass";
const char* host = "http://192.168.0.69:8080/json"; //Your BlueIris server IP goes here
const char* username = "BlueIrisUsername";
const char* password = "BlueIrisPassword";

BlueIris blueIrisClient(SSID,SSIDpass,host,username,password);


```
### BlueIris Methods

```

blueIrisClient.update();

```
This updates the Blue Iris client with the latest status of the server and cameras. This needs to be called in loop() so that ArduinoBlueIris can have the correct information. Returns true if successful, returns false if not succesful.

```

blueIrisClient.isConnected();

```
Returns true if the Blue Iris client is connected to the server.

```

blueIrisClient.isAdmin();

```
Returns true if user has Admin access to the server. False otherwise.

```

blueIrisClient.canChangeProfile();

```
Returns true if user has permission change active profile. False otherwise.

```

blueIrisClient.canPTZ();

```
Returns true if user has permission to send PTZ commands. False otherwise.

```

blueIrisClient.canAudio();

```
Returns true if user has permission to hear audio. False otherwise.

```

blueIrisClient.canAccessClips();

```
Returns true if user has permission to access clips. False otherwise.

```

blueIrisClient.canCreateClips();

```
Returns true if user has permission create clips. False otherwise.

```

blueIrisClient.hasTimeLimit();

```
Returns true if user has a time limit. False otherwise.

```

blueIrisClient.isDIOEnabled();

```
Returns true if DIO is enabled on the server. False otherwise.

```

blueIrisClient.getVersion();

```
Returns the current version of the Blue Iris server as a char*.


```

blueIrisClient.getLicense();

```
Returns the current license of the Blue Iris server as a char*.

```

blueIrisClient.getSupportLevel();

```
Returns the current support level of the Blue Iris server as a char*.

```

blueIrisClient.getTimeZone();

```
Returns the current time zone of the Blue Iris server as a char*.

```

blueIrisClient.getStreamList();

```
Returns the current available streams of the Blue Iris server as an array of char*.


```

blueIrisClient.getSoundList();

```
Returns the current available sounds of the Blue Iris server as an array of char*.

```

blueIrisClient.getWWWSoundList();

```
Returns the current available sounds in the /WWW folder of the Blue Iris server as an array of char*.

```

blueIrisClient.getProfileList();

```
Returns the available profiles of the Blue Iris server as an array of char*.

```

blueIrisClient.getScheduleList();

```
Returns the current schedules of the Blue Iris server as an array of char*.

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
