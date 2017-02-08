/*
Abrahams Thomas
February 7, 2017
CS 240 TTh 2-3:50 PM
Assembly_Menu
*/

#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	cout << "------------MENU------------" << endl;
	cout << "Drinks....................$2" << endl;
	cout << "Sandwiches................$4" << endl;

	short drinks = 0;
	short sandwiches = 0;
	short total = 0;
	cout << "How many drinks? ";
	cin >> drinks;
	cout << "How many sandwiches: ";
	cin >> sandwiches;
	
	__asm 
	{
		//Drinks			// Destination, Item 
		mov ax, drinks; // ax = drinks
		add ax, drinks; // ax = 2*drinks
		//Sandwiches
		mov bx, sandwiches; //bx = sandwiches
		add bx, sandwiches; //bx = 2*sandwiches
		add bx, sandwiches; //bx = 3*sandwiches
		add bx, sandwiches; //bx = 4*sandwiches
		//Total
		add ax, bx; //ax = ax + bx = 2*drinks + 4*sandwiches
		mov total, ax;
	}
	cout << "\tYour total bill $" << total << endl;
	system("pause");
	return 0;
}
