#include<iostream>

using namespace std;
short a, b, max;

void readData()
{

	cout << "Enter values for a and b:";
	cin >> a >> b;
}

void displayMax()
{
	cout << "maximum of " << a << " and " << b << " is " << max << endl;
}

int main() {

	__asm {
		call readData;
		mov ax, a; 
		cmp ax, b;
		Jng false1;
	true1:
		mov cx, a;
		jmp display;

	false1:
		mov cx, b;
	display:
		mov max, cx;
		call displayMax;

	}
	system("pause");

	return 0;
}
