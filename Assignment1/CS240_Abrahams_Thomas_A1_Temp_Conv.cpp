/*
Abrahams Thomas
February 7, 2017
CS 240 TTh 2-3:50 PM
Assembly_Temp_Conv
*/
#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	short tempFer = 0;
	short tempCel = 0;
	cout << "Enter temperature in Fahrenheit: ";
	cin >> tempFer;

	__asm {
		mov ax, tempFer;	//ax = tempFer
		sub ax, 32;			//ax = eax -32
		mov cx, 5;			//cx = 5
		imul ax, 5;			//ax = 5*ax = 5*(ax-32)
		cwd					//Doubles bit
		mov bx, 9;			//bx = 9
		idiv bx;			//ax = ax / bx, dx = ax mod bx
		mov tempCel, ax;	//tempCel = eax
	}
	int degreeSym = 248;
	cout << tempFer << "F" << (char)degreeSym << " is " << tempCel << "C" << (char)degreeSym << endl;
	system("Pause");
}
