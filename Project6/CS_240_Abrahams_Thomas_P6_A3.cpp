#include<iostream>

using namespace std;

short a[3][3][2];
int counter;
short sum;
short total;
void initialize()
{
	a[0][0][0] = 1;
	a[0][0][1] = 2;
	a[0][1][0] = 3;
	a[0][1][1] = 4;
	a[0][2][0] = 5;
	a[0][2][1] = 6;

	a[1][0][0] = 7;
	a[1][0][1] = 8;
	a[1][1][0] = 9;
	a[1][1][1] = 10;
	a[1][2][0] = 11;
	a[1][2][1] = 12;

	a[2][0][0] = 13;
	a[2][0][1] = 14;
	a[2][1][0] = 15;
	a[2][1][1] = 16;
	a[2][2][0] = 17;
	a[2][2][1] = 18;

}
void endGame()
{
	system("pause");
}
void printAllShirts() {
	cout << "The Total Shirts = ";
}
void printAllMedShirts() {
	cout << "The Total Medium Shirts = ";
}
void printAllShort() {
	cout << "The Total Short Sleves = ";
}
void printRedShirts() {
	cout << "The Total Red Shirts = ";
}
void printTotal()
{
	cout << total << endl;
}

int main()
{
	__asm {
		call initialize;
		mov counter, -1;
		mov cx, 0;
	getTheTotalShirts:
		inc counter;
		mov eax, counter;
		mov cx, [a + 2*eax];
		add total, cx;
		cmp counter, 17;
		jl getTheTotalShirts;
	getTotal:
		call printAllShirts;
		call printTotal;
		mov counter, -3;
		mov total, 0;
	getTheMedium:
		add counter, 5;
		mov eax, counter;
		mov cx, [a + 2 * eax];
		add total, cx;
		inc counter;
		mov eax, counter;
		mov cx, [a + 2 * eax];
		add total, cx;
		cmp counter, 17;
		jl getTheMedium;
	getTheShort:
		call printAllMedShirts;
		call printTotal;
		mov counter, 0;
		mov total, 0;
	sleeves:
		//Counter = 1
		mov eax, counter;
		//mov cx of a[1]
		mov cx, [a + 2 * eax];
		add total, cx;
		add counter, 2;
		mov eax, counter;
		mov cx, [a + 2 * eax];
		add total, cx;
		add counter, 2;
		mov eax, counter;
		mov cx, [a + 2 * eax];
		add total, cx;
		add counter, 2;
		cmp counter, 17;
		
		jl sleeves;
		call printAllShort;
		call printTotal;

	getTheRed:
		mov counter, 0;
		mov total, 0;
	redShirts:
		//Counter = 1
		mov eax, counter;
		//mov cx of a[1]
		mov cx, [a + 2 * eax];
		add total, cx;
		inc counter;
		cmp counter, 6;
		jl redShirts;
		call printRedShirts;
		call printTotal;
		call endGame;
	}
	return 0;
}
