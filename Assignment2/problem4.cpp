/*
Abrahams, Thomas
Partner: Max Krochman
CS 240
Project 3 Division, Multiplication, and Making Decisions
Part 4: Cramer's rule
*/
#include<iostream>
#include<cstdio>

using namespace std; 

short a;
short b;
short c;
short d;
short e;
short f;
short numerator;
short denominator;
short xValue;
short yValue;

void menu()
{
	cout << "This program solves the system" << endl;
	cout << "\taX+bY = c" << endl;
	cout << "\tdX+eY = f" << endl;
	cout << "Enter the values of a, b, and c: ";
	cin >> a >> b >> c;
	cout << "Enter the values of d, e, and f: ";
	cin >> d >> e >> f;
	
}
void errorMessage()
{
	cout << "You cannot divide by zero." << endl;
}
void theEnd()
{
	cout << "\tX = " << xValue << "\tY = " << yValue << endl;
	
}
void pauser()
{
	system("Pause");
}


int main()
{


	__asm {
		call menu;	//Get values for a, b, c, d, e, f
		mov ax, a;
		imul e;
		mov denominator, ax;	//Store denominator = a*e
		mov ax, b;
		imul d;					//ax = b*d
		sub denominator, ax;	//denominator = a*e - b*d
		//Check if denominator equals zero.
		//So...
		cmp denominator, 0;		//Compare zero and denominator.
		je zeroError;			//If zero then end the project.
		//Zero error did not occur.
		//Calculate y-Value
		mov ax, a;				//ax = a
		mov bx, f;				//bx = f
		imul bx;				//ax = a*f
		mov numerator, ax;		//numerator = a*f;
		mov ax, c;				//ax = c
		mov bx, d;				//bx = d
		imul bx;				//ax = c*d
		sub numerator, ax;		//numerator = a*f - c*d
		mov ax, numerator;		//ax = numerator
		cwd;					//Ready for division;
		idiv denominator;		//ax = numerator/denominator;
		mov yValue, ax;		//xValue = numerator / denominator.
		//Calculate X-Value
		mov ax, c;				//ax = c
		mov bx, e;				//bx = e
		imul bx;				//ax = c*e
		mov numerator, ax;		//numerator = c*e;
		mov ax, b;				//ax = b
		mov bx, f;				//bx = f
		imul bx;				//ax = b*f
		sub numerator, ax;		//numerator = c*e - b*f
		mov ax, numerator;		//ax = numerator
		cwd;					//Ready for division;
		idiv denominator;		//ax = numerator/denominator;
								//xValue = numerator / denominator.
		cwd;
		mov xValue, ax;
		jmp finale;			//Goes to the final step.

	zeroError:
		call errorMessage;
		jmp pausing;
	finale:
		call theEnd;
	pausing:
		call pauser;


	}

	return 0;
}
