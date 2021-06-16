#include "mbed.h"
#include "bbcar.h"
#include "bbcar_rpc.h"

Ticker servo_ticker;
PwmOut pin5(D5), pin6(D6);
BufferedSerial xbee(D1, D0);
BufferedSerial pc(USBTX, USBRX);
BBCar car(pin5, pin6, servo_ticker);

void park(Arguments *in, Reply *out);
RPCFunction rpcpark(&park, "park");

double d1, d2;
int direction;


int main(void) {
    char buf[256], outbuf[256];
    FILE *devin = fdopen(&xbee, "r");
    FILE *devout = fdopen(&xbee, "w");
    while (1) {
        memset(buf, 0, 256);
        for( int i = 0; ; i++ ) {
            char recv = fgetc(devin);
            if(recv == '\n') {
            printf("\r\n");
            break;
            }
            buf[i] = fputc(recv, devout);
        }
        RPC::call(buf, outbuf);
        printf("%s\r\n", outbuf);
    }
}


void park(Arguments *in, Reply *out)  
{
    printf("park\n");

    double velocity = 16;
    double t1;
    double t2;

    printf("park\n");
    d1 = in->getArg<double>();
    d2 = in->getArg<double>();
    direction = in->getArg<int>();

    velocity = 15.4;
    t1 = 1000*(d1+13)/velocity;
    t2 = 1000*(d2+5)/velocity;


    for (i = 0; i < direction; i++) {
      car.turn(100, 1);
      ThisThread::sleep_for(600ms);
      car.stop();
      ThisThread::sleep_for(500ms);
    }
    car.goStraight(-100);
    ThisThread::sleep_for(t1);
    car.stop();
    ThisThread::sleep_for(500ms);
    car.turn(100, 1);
    ThisThread::sleep_for(600ms);
    car.stop();
    ThisThread::sleep_for(500ms);
    car.goStraight(-100);
    ThisThread::sleep_for(t2);
    car.stop();
    
}
