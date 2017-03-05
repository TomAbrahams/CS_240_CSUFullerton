#include<iostream>

using namespace std;

//Data
int shirtArr[4][4] = { { 10, 20, 30, 40 },{ 20, 10, 40, 30 },{ 5,15,20,25 },{ 30,25,20,15 } };
int n;
int sumShirts;
int shirtHolder;

void printTotalShirts() {
	cout << "Print total shirts: " << sumShirts << endl;
}
void printLgShrirts() {
	cout << "Number of large shirts: " <<  sumShirts << endl;
}
void printBlkShirts() {
	cout << "Number of black shirts: " << sumShirts << endl;
}

int main() {

	__asm {
		mov eax, 0;
	totalShirts:
		//Note each +2 will shift.
		//[shirtArr + ebx]
		mov eax, n;

		//Adding the shirt, eax = 2 shirtArr + 2*0
		mov ebx, [shirtArr + 4 * eax];
		add shirtHolder, ebx;
		add sumShirts, ebx;
		inc n;
		cmp n, 16;
		je printTotal;
		jmp totalShirts;
	printTotal:
		call printTotalShirts;
		mov n, -2;
		mov sumShirts, 0;
	calcNumOfLargeShirts:
		add n, 4;
		mov eax, n;

		//Adding the shirt, eax = 2 shirtArr + 2*0
		mov ebx, [shirtArr + 4 * eax];
		add shirtHolder, ebx;
		add sumShirts, ebx;
		cmp n, 15;
		jge printSumLg;
		jmp calcNumOfLargeShirts;
	printSumLg:
		call printLgShrirts;
		mov n, 11; //Start at black.
		mov sumShirts, 0;
	calcNumOfBlackShrts:
		inc n;			//Increment x
		mov eax, n;		//Start at 

		//Adding the shirt, eax = 2 shirtArr + 2*0
		mov ebx, [shirtArr + 4 * eax];
		add sumShirts, ebx;
		cmp n, 15;
		jge printBlackShirts;
		jmp calcNumOfBlackShrts;
	printBlackShirts:
		call printBlkShirts;

		//+12


		//Initialize red shirts.
		//Compute total shirts
		//Need 16

	}
	//cout << "The value of shirtArr[0][0] = " << shirtArr[0][0] << endl;
	system("pause");
	return 0;
}
