# ArduinoBlueIris
Arduino API to integrate with Blue Iris Security Software JSON API

Not all functionality of the JSON API can be implemented onto the Arduino due to hardware limitations

But all useful functionality will be implemented to help DIYers better control their video security experience.

## Completed tasks:
 - Login and authenticate MD5 🥳️You do not need to expose your Blue Iris server, disable secure authentication, or create exclusions for the Arduino. The code is able to successfully authenticate through the normal handshake protocal and login to Blue Iris without any changes to the main server settings.

## Todo:

 - Implement "camlist" JSON command to generate abstracted array of type Camera
 - Link camera flags to each Camera to check isNoSignal, isMotion, isTriggered, isRecording, FPS, etc...
 - Implement "trigger" JSON command to activate recording on any Camera in array
 - Implement "ptz" JSON command to move any Camera in array
 - Implement "logout" JSON command
