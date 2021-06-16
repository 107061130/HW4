# HW4

## Setup
PwmOut pin5(D5), pin6(D6);
Ticker servo_ticker;
BufferedSerial pc(USBTX,USBRX); //tx,rx
BufferedSerial uart(A1,A0); //tx,rx
DigitalInOut pin10(D10);
BufferedSerial xbee(D1, D0);

## 1.Parking
* use "sudo python3 xbee.py" to compile it.
* use "/park/run d2 d1 k" to sen RPC command, where k is the direction(0,1,2,3).
* Then remote xbee will receive the position parameter and start to park.
![](https://i.imgur.com/xSfQLSf.png)
## 2. Follow Line
* Put the car on the straight line and the car will follow the line.

## 3. Apriltag navigation
* Let the car face apriltag by some dergree or directly, then the car will follow apriltag.
