/*
Abrahams Thomas
February 7, 2017
CS 240
TTh 2-3:50 PM
*/
#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	int tempFer = 0;
	int tempCel = 0;
	cout << "Enter temperature in Fahrenheit: ";
	cin >> tempFer;

	__asm {
		mov eax, tempFer; //eax = tempFer
		sub eax, 32; //eax = eax -32
		imul eax, 5; //eax = 5*eax = 5*(eax-32)
		sub edx, edx; //edx = 0
		mov ebx, 9; //eax = (5/9)*(eax - 32)
		idiv ebx; 
		mov tempCel, eax; //tempCel = eax
	}
	int degreeSym = 248;
	cout << tempFer << "F" << (char)degreeSym << " is " << tempCel << "C" << (char)degreeSym << endl;
	system("Pause");
}
