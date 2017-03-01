/*
	Abrahams, Thomas
	CS 240
	Assignment No. 5
	Problem 1
*/

#include<iostream>

using namespace std;

short comparison;
short registerNum;
short bitNum;
short numOfPrinters;
short numOfFloppy;
short numOfRam;
short bitValue;
short counter = 0;
short currentNum;

short myArray[16];

void prompt() {
	cout << "What number is in the register ";
	cin >> registerNum;


}
void space()
{
	cout << " ";
}
void results() {
	cout << "The number of printers connected to the computer " << numOfPrinters << endl;
	cout << "The number of floppy drives " << numOfFloppy << endl;
	cout << "The size of RAM " << numOfRam << endl;
	for (int i = 0; i < 16; i++)
	{
		if (i % 4 == 0)
			cout << " ";
		if (myArray[i] != 0)
			cout << "1";
		else
			cout << "0";
	}
	cout << endl;
	system("pause");
	
}
void getBitNum()
{
	currentNum = myArray[15 - bitNum];
}
void getNum()
{
	cout << currentNum;
}

void storeInArray()
{
	myArray[counter] = currentNum; 
}
int main() {
	__asm {
	menuPrompt:

		mov registerNum, 0xCE9C;
		mov cx, 1;
		shl cx, 15;				//Shift the number 15 over. 1000 0000 0000 0000
		mov comparison, cx;


	calculation:
		mov cx, comparison;
		mov ax, registerNum;			//Number is in.
		and ax, cx;				//Gets bx as 1 or 0
		//Make the cases for counter.
		//Printer 14 bit
		mov currentNum, ax;		//Gets the bit number.
		call storeInArray;
		inc counter;
		mov dx, counter;
		
		mov ax, registerNum;
		shl ax, 1;
		mov registerNum, ax;
		cmp dx, 15;
		jle calculation;
	printers:
		//bit number 
		
		mov bitNum, 14; //get the 14th bit.
		call getBitNum;	//14th bit value is in currentNum.
		cmp currentNum, 0;	//Seeing if bit 14 is zero.
		je bit14isZero;
		jmp bit14isOne;
	bit14isZero:
		mov bitValue, 0;
		mov bitNum, 15;
		call getBitNum;		//Bit value is in current num;
		cmp currentNum, 0;
		je bit15isZero;
		jmp bit15isOne;
	bit14isOne:
		mov bitValue, 1;
		mov bitNum, 15;
		call getBitNum;		//Bit value is in current num;
		cmp currentNum, 0;
		je bit15isZero;
		jmp bit15isOne;
	bit15isZero:
		jmp calcPrinter;
	bit15isOne:
		add bitValue, 10;
		jmp calcPrinter;
		//Printers handled.
	calcPrinter:
		cmp bitValue, 0;
		je zeroPrinters;
		cmp bitValue, 1;
		je onePrinters;
		cmp bitValue, 10;
		je twoPrinters;
		cmp bitValue, 11;
		je threePrinters;
	zeroPrinters:
		mov numOfPrinters, 0;
		jmp floppyDrives;
	onePrinters:
		mov numOfPrinters, 1;
		jmp floppyDrives;
	twoPrinters:
		mov numOfPrinters, 2;
		jmp floppyDrives;
	threePrinters:
		mov numOfPrinters, 3;
		jmp floppyDrives;
	floppyDrives:
		//bit number 

		mov bitNum, 6; //get the 14th bit.
		call getBitNum;	//14th bit value is in currentNum.
		cmp currentNum, 0;	//Seeing if bit 14 is zero.
		je bit6isZero;
		jmp bit6isOne;
	bit6isZero:
		mov bitValue, 0;
		mov bitNum, 7;
		call getBitNum;		//Bit value is in current num;
		cmp currentNum, 0;
		je bit7isZero;
		jmp bit7isOne;
	bit6isOne:
		mov bitValue, 1;
		mov bitNum, 7;
		call getBitNum;		//Bit value is in current num;
		cmp currentNum, 0;
		je bit7isZero;
		jmp bit7isOne;
	bit7isZero:
		jmp calcFloppy;
	bit7isOne:
		add bitValue, 10;
		jmp calcFloppy;
		//Printers handled.
	calcFloppy:
		cmp bitValue, 0;
		je oneFloppy;
		cmp bitValue, 1;
		je twoFloppy;
		cmp bitValue, 10;
		je threeFloppy;
		cmp bitValue, 11;
		je fourFloppy;
	oneFloppy:
		mov numOfFloppy, 1;
		jmp ram;
	twoFloppy:
		mov numOfFloppy, 2;
		jmp ram;
	threeFloppy:
		mov numOfFloppy, 3;
		jmp ram;
	fourFloppy:
		mov numOfFloppy, 4;
		jmp ram;
	/*
		THIS IS FOR RAM
	*/
	ram:

		mov bitNum, 2;		//get the 2nd bit.
		call getBitNum;		//14th bit value is in currentNum.
		cmp currentNum, 0;	//Seeing if bit 14 is zero.
		je bit2isZero;
		jmp bit2isOne;
	bit2isZero:
		mov bitValue, 0;
		mov bitNum, 3;		//get the 3rd bit.
		call getBitNum;		//Bit value is in current num;
		cmp currentNum, 0;
		je bit3isZero;
		jmp bit3isOne;
	bit2isOne:
		mov bitValue, 1;
		mov bitNum, 3;		//get the 3rd bit.
		call getBitNum;		//Bit value is in current num;
		cmp currentNum, 0;
		je bit3isZero;
		jmp bit3isOne;
	bit3isZero:
		jmp calcRam;
	bit3isOne:
		add bitValue, 10;
		jmp calcRam;
		//Printers handled.
	calcRam:
		cmp bitValue, 0;
		je ram16k;
		cmp bitValue, 1;
		je ram32k;
		cmp bitValue, 10;
		je ram48k;
		cmp bitValue, 11;
		je ram64k;
	ram16k:
		mov numOfRam, 16;
		jmp finale;
	ram32k:
		mov numOfRam, 32;
		jmp finale;
	ram48k:
		mov numOfRam, 48;
		jmp finale;
	ram64k:
		mov numOfRam, 64;
		jmp finale;

	finale:
		call results;



	}

}
