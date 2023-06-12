# ArduinoBlueIris
Arduino API to integrate with Blue Iris Security Software JSON API

Not all functionality of the JSON API can be implemented onto the Arduino due to hardware limitations

But all useful functionality will be implemented to help DIYers better control their video security experience.

Blue Iris JSON API is documented here:
https://blueirissoftware.com/BlueIris.PDF

## Completed tasks:
 - Login and authenticate MD5 🥳️You do not need to expose your Blue Iris server, disable secure authentication, or create exclusions for the Arduino. The code is able to successfully authenticate through the normal handshake protocal and login to Blue Iris without any changes to the main server settings.

## Todo:

 - Implement "camlist" JSON command to generate abstracted array of type Camera
 - Link camera flags extracted from server's JSON response to each Camera to check isNoSignal, isMotion, isTriggered, isRecording, FPS, etc...
 - Implement a BlueIris.update() method to update status of server and Cameras
 - Implement "trigger" JSON command to activate recording on any Camera in array
 - Implement "ptz" JSON command to move any Camera in array
 - Implement "logout" JSON command


JSON commands pertaining to window management are currently not a priority and will possibly not be implemented. If your use case involves using an Arduino to to wirelessly switch between cameras on your screen, and select different cameras to be full screen. Then please open an issue and I will add window management to the priority list as well.
