/* 
* BluetoothInterface.cpp
*
* Created: 24.05.2018 09:35:26
* Author: Henri
*/


#include "BluetoothInterface.h"
#include <HardwareSerial.h>
#include "Arduino.h"


// default constructor
BluetoothInterface::BluetoothInterface(){
	m_diretionX=0;
	m_diretionY=0;
	m_diretionZ=0;
	pinMode(LED_BUILTIN, OUTPUT);
	pinMode(12, OUTPUT); //also pin 12 as LED output

/*	Serial.begin(9600);         //Sets the data rate in bits per second (baud) for serial data transmission
	Serial.println("This is the arduino for Hexapod!!!");
	Serial.println(" ");
	Serial.println("To connect, start the LED Controller App on your Smartphone");
	Serial.println("and connect to Bluetooth HC-05");
*/	
	
	BluetoothSerial.begin(9600);         //Sets the data rate in bits per second (baud) for serial data transmission
} //BluetoothInterface

unsigned char BluetoothInterface::readInput(){

	int i;
	char appValue[7];
	int count = 0;
	if(BluetoothSerial.available() > 0)
	{
		for (i=0; i<7; i++)
		{
				//digitalWrite(LED_BUILTIN, HIGH); 
				appValue[i] = BluetoothSerial.read();
			
		}
		m_diretionX =  (int) appValue[1]-'0';
		Serial.println(m_diretionX);
		
		m_diretionY =  (int) appValue[3]-'0';
		Serial.println(m_diretionY);
		
		m_diretionZ =  (int) appValue[5]-'0';
		Serial.println(m_diretionZ);		
	}
	count = 0;
}
int BluetoothInterface::calcAngle(int appValue){
	int param = 10;
	//int appValue = (int) tempappValue,
	
	appValue = appValue*param;
	return appValue;

}
int BluetoothInterface::getDirectionX(){
	return m_diretionX;

}

int BluetoothInterface::getDirectionY(){
	return m_diretionY;
}

int BluetoothInterface::getDirectionZ(){
	return m_diretionZ;
}
// default destructor
BluetoothInterface::~BluetoothInterface()
{
} //~BluetoothInterface