# overview

This code is for a program that performs binary sum operations on a microcontroller using the Arduino platform.
It reads digital inputs from specific pins, performs bitwise summation operations, considers bit carry,
and displays the result on the output pins.
The code was designed with the aim of being a sum calculator in which two binary numbers of up to 4 digits are added and the sum showing the result at the end.

the code uses 13 pins, 8 of which are input numbers 1 to perform the sum and 5 are output
```cpp
//Pin configuration
void setup(){
	pinMode(0, INPUT);
	pinMode(1, INPUT);
	pinMode(2, INPUT);
	pinMode(3, INPUT);
	pinMode(4, INPUT);
	pinMode(5, INPUT);
	pinMode(6, INPUT);
	pinMode(7, INPUT);
	pinMode(8, OUTPUT);
	pinMode(9, OUTPUT);
	pinMode(10, OUTPUT);
	pinMode(11, OUTPUT);
	pinMode(12, OUTPUT);
	pinMode(13, INPUT);
}
```
After entering the numbers after pressing the number button 13 the sum function will be performed
following the developed code
```cpp
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
```
and the result of the sum will be shown on the last 4 pins.
