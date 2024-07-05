# ARDU.INO CODE
# =====================================
# ARDU.INO CODE documentation
## version: 1.0
## by: Alan M. Cornely
## Date: 06/13/2024
# =====================================

# index

welcome to our software and here is some information to read about our code.

- [overview] (https://github.com/AlanCornely/Trabalho-2-INO/blob/main/docs/overview.md)
- [installation] (https://github.com/AlanCornely/Trabalho-2-INO/blob/main/docs/installation.md)
- [usage] (https://github.com/AlanCornely/Trabalho-2-INO/blob/main/docs/usage.md)
- [contributing] (https://github.com/AlanCornely/Trabalho-2-INO/blob/main/docs/contributing.md)
- [license] (https://github.com/AlanCornely/Trabalho-2-INO/blob/main/docs/LICENSE)

## Description
### This Arduino code performs the sum of two 4-bit numbers and displays the result on digital output pins. The program reads two 4-bit numbers from the digital input pins, performs the bitwise sum considering the carry bit, and then writes the result and the resulting carry bit to the output pins.

### Global Variables:
-- **int sum = 13;**

It is the Input Pin used to activate the sum operation.

-- **int carryBit = 0;**

It is the Transport Bit initialized to 0.

-- **int nib1a, nib1b, nib1c, nib1d = 0;**

It is the Bits of the first 4-bit number..

-- **int nib2a, nib2b, nib2c, nib2d = 0;**

It is the Bits of the second 4-bit number..

-- **int res1a, res1b, res1c, res1d = 0;**

It is the Bit of the sum result.

### setup() function
Configures the digital pins as input or output. Input is the input and output is the output respectively.
```cpp
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
### Function 'sumBit'
Performs the sum of three bits, returning the result bit.

```cpp
int sumBit(int b1a, int b2a, int cBit){
 int bitResult = 0;
 if ((b1a ^ b2a) ^ cBit){
 bitResult = 1;
 } else {
 bitResult = 0;
 }
 return bitResult;
}
```
**Parameters:**

--int b1a - First input bit.

--int b2a - Second input bit.

--int cBit - Carry bit.

**Return:**

--int - Sum result bit.

### Function 'sumCarryBit'

Calculates the new carry bit after summing three bits.

```cpp
int sumCarryBit(int b1a, int b2a, int cBit){
 if ((b1a && b2a) || (b1a && cBit) || (b2a && cBit)){
 cBit = 1;
 } else {
 cBit = 0;
 }
 return cBit;
}
```
**Parameters:**

--int b1a - First input bit.

--int b2a - Second input bit.

--int cBit - Carry bit.

**Return:**

--int - New carry bit.

###Loop() function

Reads the input bits, performs the sum if the control pin is activated and writes the result to the output pins.

```cpp
void loop(){
 sum = digitalRead(13);
 nib1a = digitalRead(0);
 nib1b = digitalRead(1);
 nib1c = digitalRead(2);
 nib1d = digitalRead(3);
 nib2a = digitalRead(4);
 nib2b = digitalRead(5);
 nib2c = digitalRead(6);
 nib2d = digitalRead(7);

 if (sum == 1){
 carryBit = 0;
 res1a = sumBit(nib1a, nib2a, carryBit);
 carryBit = sumCarryBit(nib1a, nib2a, carryBit);
 res1b = sumBit(nib1b, nib2b, carryBit);
 carryBit = sumCarryBit(nib1b, nib2b, carryBit);
 res1c = sumBit(nib1c, nib2c, carryBit);
 carryBit = sumCarryBit(nib1c, nib2c, carryBit);
 res1d = sumBit(nib1d, nib2d, carryBit);
 carryBit = sumCarryBit(nib1d, nib2d, carryBit);
 }
 digitalWrite(8, res1a);
 digitalWrite(9, res1b);
 digitalWrite(10, res1c);
 digitalWrite(11, res1d);
 digitalWrite(12, carryBit);
}
```
**Operations:**

--Reads the status of the control pin (sum).

--Reads the bits of the two 4-bit numbers (nib1a to nib1d and nib2a to nib2d).

--If the control pin is activated (sum == 1), performs bitwise summation, updating the carry bit.

--Write the result of the sum to the output pins (res1a to res1d and carryBit).
