/*

 'codesend' hacked from 'send' by @justy
 
 - The provided rc_switch 'send' command uses the form systemCode, unitCode, command
   which is not suitable for our purposes.  Instead, we call 
   send(code, length); // where length is always 24 and code is simply the code
   we find using the RF_sniffer.ino Arduino sketch.

 Usage: ./codesend decimalcode
 (Use RF_Sniffer.ino to check that RF signals are being produced by the RPi's transmitter)
 */

#include "RCSwitch.h"
#include <stdlib.h>
#include <stdio.h>
     

int main(int argc, char *argv[]) {
    
    // This is the pin for the TX according to the WiringPi numbering system
    // Consult https://projects.drogon.net/raspberry-pi/wiringpi/pins/
    // for more information.
    int PIN = 1; //Changed to from the default to WiringPi pin #1 (RPI pin # 12).
    
    // Parse the firt parameter to this command as an integer
    int code = atoi(argv[1]);
    
    if (wiringPiSetup () == -1) return 1;
	printf("sending code[%i]\n", code);
	RCSwitch mySwitch = RCSwitch();
	mySwitch.enableTransmit(PIN);
    
    mySwitch.send(code, 24);
    
	return 0;

}
