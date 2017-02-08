/*
Abrahams Thomas
February 7, 2017
CS 240
TTh 2-3:50 PM
Assembly_Area_Perm
*/
#include<iostream>
#include<cstdio>

using namespace std;

int main() {
	cout << "        /|\\        " << "\t---------------" << endl;
	cout << "       / | \\       " << "\t|             |" << endl;
	cout << "    a /  |  \\ b    " << "\t|             | width" << endl;
	cout << "     /  h|   \\     " << "\t|             |" << endl;
	cout << "    /    |    \\    " << "\t|             |" << endl;
	cout << "   /     |     \\   " << "\t---------------" << endl;
	cout << "   -------------   " << "\t     length    " << endl;
	cout << "         c         " << endl;

	int a = 0;
	int b = 0;
	int c = 0;
	int h = 0;

	int permTri = 0;
	int areaTri = 0;

	int permRec = 0;
	int areaRec = 0;

	int theWidth = 0;
	int theLength = 0;
	
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
		cdq;
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
	cout << "\tTriangle" << endl;
	cout << "\t\tArea.........................." << areaTri << endl;
	cout << "\t\tPerimeter....................." << permTri << endl;
	cout << "\tRectangle" << endl;
	cout << "\t\tArea.........................." << areaRec << endl;
	cout << "\t\tPerimeter....................." << permRec << endl;

	system("Pause");
	return 0;
}
