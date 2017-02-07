/*
  Abrahams Thomas
  February 7, 2017
  CS 240
  TTh 2-3:50 PM
*/

#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	cout << "------------MENU------------" << endl;
	cout << "Drinks....................$2" << endl;
	cout << "Sandwiches................$4" << endl;

	int drinks = 0;
	int sandwiches = 0;
	int total = 0;
	cout << "How many drinks? ";
	cin >> drinks;
	cout << endl;
	cout << "How many sandwiches: ";
	cin >> sandwiches;
	


	__asm 
	{
		//Drinks			// Destination, Item 
		mov eax, drinks; // eax = drinks
		add eax, drinks; // eax = 2*drinks
		//Sandwiches
		mov ebx, sandwiches; //ebx = sandwiches
		add ebx, sandwiches; //ebx = 2*sandwiches
		add ebx, sandwiches; //ebx = 3*sandwiches
		add ebx, sandwiches; //ebx = 4*sandwiches
		//Total
		add eax, ebx; //eax = eax + ebx = 2*drinks + 4*sandwiches
		mov total, eax;
	}
	cout << "\tYour total bill $" << total << endl;
	system("pause");
	return 0;
}
