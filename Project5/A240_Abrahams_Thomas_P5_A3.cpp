/*
  Abrahams, Thomas
  CS 240
  February 26, 2017
*/

#include <iostream>

using namespace std;

short comparison;
short registerNum;
short bitNum;
short numSprinklersOn;		//Total Sprinklers On.
short numSprinklersOff;
short sprinklerNum = 1;		//Current Sprinkler
short bitValue;
short counter = 0;
short currentNum;
short placeNum;
short myArray[16];
short defectiveArray[16];

void prompt() {
	cout << "What number is in the register ";
	cin >> registerNum;


}
void space()
{
	cout << " ";
}

void getBitNum()
{
	currentNum = myArray[15 - bitNum];
}
void putCurrentNum()
{
	currentNum = myArray[bitNum];
}
void putDefectSprink()
{
	defectiveArray[numSprinklersOff] = placeNum;
}
void getNum()
{
	cout << currentNum;
}

void storeInArray()
{
	myArray[counter] = currentNum;
}
void printBinary()
{
	cout << "AX = ";
}
void printSpace()
{
	cout << " ";
}
void printZero()
{
	cout << "0";
}
void printOne()
{
	cout << "1";
}
void printReturnChar()
{
	cout << endl;
}
void printDefects()
{
	cout << defectiveArray[counter];
}
void endgame()
{
	cout << numSprinklersOn << " sprinklers are ON" << endl;
	cout << "Defective Sprinklers: ";
	
}
void pausingIt()
{
	cout << endl;
	system("pause");
}
int main() {
	__asm {
	menuPrompt:

		mov registerNum, 0x6A2F;
		mov cx, 1;
		shl cx, 15;				//Shift the number 15 over. 1000 0000 0000 0000
		mov comparison, cx;


	calculation:
		mov cx, comparison;
		mov ax, registerNum;			//Number is in.
		and ax, cx;				//Gets bx as 1 or 0

		mov currentNum, ax;		//Gets the bit number.
		call storeInArray;
		inc counter;
		mov dx, counter;

		mov ax, registerNum;
		shl ax, 1;
		mov registerNum, ax;
		cmp dx, 15;
		jle calculation;
		mov bitNum, 0;		//Counter bitNum.
		mov counter, 0;
		call printBinary;
	printSprinklers:
		//Need to get current sprinkler.
		call putCurrentNum;		//currentNum= myArray[bitNum];
		mov ax, counter;	//counter = ax;
		//if counter == 0 then print zero. else print 1.
		inc bitNum;			//bitNum
		inc sprinklerNum;	//sprinklerNum++
		inc counter;
		cmp counter, 16;
		jg finale;
		cmp currentNum, 0;
		je printMyZero;
		jmp printMyOne;
	printMyZero:
		call printZero;
		mov ax, bitNum;
		mov bx, 17;
		sub bx, ax;
		mov placeNum, bx;
		call putDefectSprink;	//defectiveArray[numSprinklersOff] = bitNum;
		inc numSprinklersOff;

		jmp printSpaceSep;
	printMyOne:
		call printOne;
		inc numSprinklersOn;
		jmp printSpaceSep;
	printSpaceSep:
		mov ax, counter;
		mov bx, 4;
		cwd;
		idiv bx;
		cmp dx, 0;
		je spacer;
		jmp printSprinklers;
	spacer:
		call printSpace;
		jmp printSprinklers;
	finale:
		call printReturnChar;
		//Print out the numbers;
		mov counter, 0; //Counter initialized.

		call endgame;

	defective:
		
		mov bx, numSprinklersOff;
		call printDefects;	//Prints out defective item.
		call printSpace;
		inc counter;

		cmp counter, bx;
		jl defective;
		
		
	finished:
		call pausingIt;
		
	}
	return 0;
}
