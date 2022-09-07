# portable-webserial
Turn any ESP8266 into portable and wireless web based serial monitor!  
<img src="https://user-images.githubusercontent.com/61390950/188765985-2a463825-b955-4ec7-96aa-313d6251175b.png" height="200px" width="300px">  



## Setup
1. Install [platform.io](https://docs.platformio.org/en/latest/core/installation/index.html)
2. Install libs
```
pio lib install
```

3. Change `wifi_name` and `password` in `src/main.cpp` to your.

4. Build and upload project
```
pio run --target upload && pio device monitor
```
Now wait for it to build and upload.  
After that it will print the ip address of the esp8266
Open it in the browser like this:  
```
http://<ip>/webserial
```

Now everything that send to RX will be printed in the page in the browser in live,  
And everything you type and sent in the browser will be send to TX.
<img src="https://user-images.githubusercontent.com/61390950/188766563-96fd7f55-c7d6-4d55-a2af-7af41d8c18f6.png" height="250px" width="600px">  

