#include <Arduino.h>

// global variables
int soma = 13; //sum input to perform the sum
int carryBit = 0; //carry bit when one number will go from 1 to 0
int nib1a,nib1b,nib1c,nib1d = 0;
int nib2a,nib2b,nib2c,nib2d = 0;
int res1a,res1b,res1c,res1d = 0;

//Pin configuration
void setup(){
	pinMode(0, INPUT); //input of the first number in binary
	pinMode(1, INPUT); //input of the second number in binary
	pinMode(2, INPUT); //input of the third number in binary
	pinMode(3, INPUT); //input of the fourth number in binary
	pinMode(4, INPUT); //input of the fifth number in binary
	pinMode(5, INPUT); //input of the sixth number in binary
	pinMode(6, INPUT); //input of the seventh number in binary
	pinMode(7, INPUT); //input of the eighth number in binary
	pinMode(8, OUTPUT); //output of the number after sum
	pinMode(9, OUTPUT); //output of the number after sum
	pinMode(10, OUTPUT); //output of the number after sum
	pinMode(11, OUTPUT); //output of the number after sum
	pinMode(12, OUTPUT); //output of the number after sum
	pinMode(13, INPUT); //carry bit 
}

// Performs the bitwise sum operation between variables b1a and b2a, also considering the transport bit cBit.int somaBit(int b1a, int b2a, int cBit){
	int bitResult = 0;
	int aux1, aux2 = 0;
	if ((b1a ^ b2a) ^ cBit){
		bitResult = 1;
	}else{
		bitResult = 0;
	}
	return bitResult;
}

//Calculates the new value of the transport bit (cBit) after the sum of bits b1a and b2a.
int somaCarryBit(int b1a, int b2a, int cBit){
	int aux1, aux2 = 0;
	if ((b1a && b2a)||(b1a && cBit)||(b2a && cBit)){
		cBit = 1;
	}else{
		cBit = 0;
	}
	return cBit;
}

//main scope
void loop(){
	soma = digitalRead(13); 
	nib1a = digitalRead(0); //entry number
	nib1b = digitalRead(1); //entry number
	nib1c = digitalRead(2); //entry number
	nib1d = digitalRead(3); //entry number
	nib2a = digitalRead(4); //entry number
	nib2b = digitalRead(5); //entry number
	nib2c = digitalRead(6); //entry number
	nib2d = digitalRead(7); //entry number

	if (soma == 1){
		carryBit = 0;
		res1a = somaBit(nib1a,nib2a,carryBit);
		carryBit = somaCarryBit(nib1a,nib2a,carryBit);
		res1b = somaBit(nib1b,nib2b,carryBit);
		carryBit = somaCarryBit(nib1b,nib2b,carryBit);
		res1c = somaBit(nib1c,nib2c,carryBit);
		carryBit = somaCarryBit(nib1c,nib2c,carryBit);
		res1d = somaBit(nib1d,nib2d,carryBit);
		carryBit = somaCarryBit(nib1d,nib2d,carryBit);
	}
	digitalWrite(8,res1a); //return of the number after the sum
	digitalWrite(9,res1b); //return of the number after the sum
	digitalWrite(10,res1c); //return of the number after the sum
	digitalWrite(11,res1d); //return of the number after the sum
	digitalWrite(12,carryBit); //carrybit
}
