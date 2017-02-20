/*
Thomas Abrahams, Max Krochman
CS 240
February 18, 2017
Question 4: Fahrenheit to Celsius
*/
#include<iostream>

using namespace std;

int tempFah;
int tempCel;
char continueChar;

void menu()
{
	cout << "Enter temperature in Fahrenheit: ";
	cin >> tempFah;

}
void result()
{
	cout << "\t" << tempFah << " F is " << tempCel << " C";
	cout << "\nCONTINUE(y/n)? ";
	cin >> continueChar;
	
}
void finished()
{
	system("pause");
}

int main()
{
	__asm {
		//Need to get numbers.
	theMenu:
		call menu;
		//Numbers are in. Time to do conversion.
		mov eax, tempFah;	//eax = tempFah
		sub eax, 32;		//eax = tempFah -32
		imul eax, 5;		//eax = 5*(tempFah-32)
		cdq;				//prepare for division.
		mov ebx, 9;			//divide by nine
		idiv ebx;			//eax = (5/9)*(tempFah-32)
		mov tempCel, eax;	//Store converted celsius to tempCel
		call result;
		cmp continueChar, 'y';	//See if continue char is y.
		je theMenu;				//Go back to jump equal. 
	finale:
		call finished;


	}
	return 0;
}
