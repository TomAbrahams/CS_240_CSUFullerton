#include<iostream>
#include<cstdlib>
#include <ctime>
using namespace std;

//Variables.
int theValue;
int secondValue;
int currentNum;

int randomNum;

int binaryArr[16];
int floorArr[16];
int comparison;

int counter;
int theFloor;
int invCounter;

//Need the number for the item.
//Need an array that holds the values.
//Need a way to print out the zeros.
//Need a way to get the floors.
void random()
{
	srand(time(NULL));
	randomNum = (rand() % 32766);
	
}
void storeInArray()
{
	binaryArr[counter] = currentNum;
}
void storeBit()
{
	currentNum = binaryArr[counter];
}
void getFloor()
{
	currentNum = binaryArr[invCounter];
}
void theFloorsAre()
{
	cout << "\r\nThe floors are ";
}
void ringedFloor()
{
	cout << theFloor << " ";
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

void pausingIt()
{
	cout << endl;
	system("pause");
}
int main()
{
	__asm {
		//mov theValue, 0x910C;
		mov theValue, 0;
		mov ecx, 1;
		shl ecx, 15;		
	genRandom:
		//10 random numbers.
		call random;		//Gets random number.
		mov eax, randomNum;		//Store ax = random
		add eax, 2;			//Add 2 to do bit shift for or. 
		mov ebx, theValue 
		or ebx, eax;	//Makes value or statement.
		mov theValue, ebx;	//The value holds the final value from the randoms.
		inc counter;
		cmp counter, 10;
		je empezar;
		jmp genRandom;
		
	empezar:
		mov ecx, theValue;
		mov secondValue, ecx;
		mov counter, 0;
		mov ecx, 1;
		shl ecx, 15;				//Shift the number 15 over. 1000 0000 0000 0000
		mov comparison, ecx;
		call printBinary;
	calculation:
		mov ecx, comparison;
		mov eax, theValue;			//Number is in.
		and eax, ecx;				//Gets bx as 1 or 0
								//Make the cases for counter.
								//Printer 14 bit
		mov currentNum, eax;		//Gets the bit number.
		call storeInArray;
		inc counter;
		mov edx, counter;

		mov eax, theValue;
		shl eax, 1;
		mov theValue, eax;
		cmp edx, 15;
		jle calculation;
		mov counter, 0;
		mov invCounter, 15;
	printTheArray:
		mov eax, counter;
		call storeBit;
		//inc counter;
		mov eax, counter;
		cmp eax, 16;
		je initFloors;

		cmp currentNum, 0;
		je printMyZero;
		jmp printMyOne;
	printMyZero:
		call printZero;
		inc counter;
		mov eax, invCounter;
		mov ebx, 17;
		sub ebx, eax;
		jmp printSpaceSep;
	printMyOne:
		call printOne;
		inc counter;
		jmp printSpaceSep;
	printSpaceSep:
		mov eax, counter;
		mov ebx, 4;
		cdq;
		idiv ebx;
		cmp edx, 0;
		je spacer;
		jmp printTheArray;
	spacer:
		call printSpace;
		jmp printTheArray;
	initFloors:
		//get me the number. if counter = 1
		//mov theFloor, 
		mov counter, 0;
		mov ecx, 1;
		shl ecx, 15;				//Shift the number 15 over. 1000 0000 0000 0000
		mov comparison, ecx;
		call theFloorsAre;			//Prints the floors are;
	checkingFloors:
		mov ecx, comparison;
		mov eax, secondValue;			//Number is in.
		and eax, ecx;				//Gets bx as 1 or 0
									//Make the cases for counter.
									//Printer 14 bit
		mov currentNum, eax;		//Gets the bit number.
		inc counter;
		mov edx, counter;
		mov eax, secondValue;
		shl eax, 1;
		mov secondValue, eax;
		mov eax, counter;
		cmp eax, 16;
		je finale;

		cmp currentNum, 0;
		je checkingFloors;
		jmp floorBitOne;
	floorBitOne:
		//I know that this thing is one.
		mov theFloor, 17;
		mov eax, theFloor;
		sub eax, counter;
		//sub eax, 1;
		mov theFloor, eax;
		call ringedFloor;
		cmp counter, 17;
		jle checkingFloors;
	finale:
		call pausingIt;
	}
	return 0;
}
