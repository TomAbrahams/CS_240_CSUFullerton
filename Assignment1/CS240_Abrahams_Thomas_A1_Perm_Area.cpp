/*
Abrahams Thomas
February 7, 2017
CS 240
TTh 2-3:50 PM
*/
#include<iostream>
#include<cstdio>

using namespace std;

int main() {
	cout << "        /|\        " << endl;
	cout << "       / | \       " << endl;
	cout << "    a /  |  \ b    " << endl;
	cout << "     /  h|   \     " << endl;
	cout << "    /    |    \    " << endl;
	cout << "   /     |     \   " << endl;
	cout << "   -------------   " << endl;
	cout << "         c         " << endl;

	cout << "------------" << endl;
	cout << "|          |" << endl;
	cout << "|          | width" << endl;
	cout << "|          |" << endl;
	cout << "------------" << endl;
	cout << "    length  " << endl;

	unsigned int a = 0;
	unsigned int b = 0;
	unsigned int c = 0;
	unsigned int h = 0;

	unsigned int permTri = 0;
	unsigned int areaTri = 0;

	unsigned int permRec = 0;
	unsigned int areaRec = 0;

	unsigned int theWidth = 0;
	unsigned int theLength = 0;
	
	cout << "Enter the values of a,b,c and h for the rectangle: ";
	cin >> a >> b >> c >> h;
	cout << "Enter the length and the width of the triangle: ";
	cin >> theLength >> theWidth;
	//Calculation portions
	__asm {
		//Perm triangle
		mov eax, a; //eax = a
		add eax, b; //eax = eax + b
		add eax, c; //eax = eax + c
		mov permTri, eax; //permTri = eax;
		//Area triangle
		mov eax, h; //eax = h
		
		mov ebx, 2; // ebx = 2;
		imul eax, c; //eax = eax*c
		sub edx, edx; //zero edx
		idiv ebx; // eax = eax/2
		mov areaTri, eax; //areaTri = eax
		//Perm Square
		mov eax, theWidth; //eax = width
		add eax, eax; //eax = eax+ eax
		mov ebx, theLength; //ebx = length
		add eax, ebx; //eax = eax + length
		add eax, ebx; //eax = eax + length = 2*width + 2*length
		mov permRec, eax; //permRec = eax
		//Area Square
		mov eax, theWidth; //eax = width
		imul eax, theLength; //eax = eax*length = length*width
		mov areaRec, eax; //areaRec = eax;
		
	}
	cout << "Triangle" << endl;
	cout << "\tArea.........................." << areaTri << endl;
	cout << "\tPerimeter....................." << permTri << endl;
	cout << "Rectangle" << endl;
	cout << "\tArea.........................." << areaRec << endl;
	cout << "\tPerimeter....................." << permRec << endl;

	system("Pause");
	return 0;
}
