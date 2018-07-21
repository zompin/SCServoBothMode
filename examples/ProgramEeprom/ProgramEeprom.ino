#include <SoftwareSerial.h>
#include <SCServoBothMode.h>

int LEDpin = 13;
SCServo SERVO(HARD_MODE);
int baudRates[8] = {
	1000000,
	500000,
	250000,
	128000,
	115200,
	76800,
	57600,
	38400
};

void setup(){
	pinMode(LEDpin, OUTPUT);
	SERVO.LockEprom(0xfe, 0);
	delay(100);
	for(byte i = 0; i < 8; i++){
		SERVO.init(baudRates[i]);
		delay(100);
		digitalWrite(LEDpin, LOW);
		SERVO.WriteID(0xfe, 1);
		delay(100);
		SERVO.WriteLimitAngle(0xfe, 0, 1023);
		delay(100);
		SERVO.WriteLimitTroque(0xfe, 1023);
		delay(100);
		SERVO.WritePunch(0xfe, 50);
		delay(100);
		SERVO.WriteDeadBand(0xfe, 1, 1);
		delay(100);
		SERVO.WritePID(0xfe, 15, 0, 30);
		delay(100);
		SERVO.WriteBaund(0xfe, B_115200);
		delay(100);
		digitalWrite(LEDpin, HIGH);
		delay(100);
	}
	SERVO.LockEprom(0xfe, 1);
}

void loop(){

}
