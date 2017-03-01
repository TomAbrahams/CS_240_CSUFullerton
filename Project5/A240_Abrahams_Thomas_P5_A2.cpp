#include<iostream>

using namespace std;

int code;
int sum;
int leftOver =0;
char charChoice;
void menu()
{
	cout << "Enter a four digit in PIN number: ";
	cin >> code;

}
void theEven()
{
	cout << code << " is a valid PIN number" << endl;
}
void theOdd()
{
	cout << code << " is not a valid PIN number" << endl;
}
void tryAgain()
{
	cout << "Do you want to try again(y/n)?";
	cin >> charChoice;

}
void wrongChar()
{
	cerr << "Incorrect choice please choose again." << endl;
}
void theEnd()
{
	system("pause");
}

int main() {
	__asm {
	beginCode:
		call menu;
		mov leftOver, 0;
		mov sum, 0;
		//if code is less than 10000
		mov eax, code;		//eax = code.
		cdq;				//Get ready for division.
		mov ebx, 1000;		//Gets WXYZ, W in eax XYZ in edx
		idiv ebx;
		add sum, eax;
		//Here it is
		mov leftOver, edx;		//remainder = XYZ;
		mov eax, leftOver;		//eax has remainder.
		cdq;
		mov ebx, 100;
		idiv ebx;				//eax has X, from XYZ;
		add sum, eax;			//Sum = W+X
		mov leftOver, edx;		//remainder = YZ
		//Now 10
		mov eax, leftOver;		//eax has remainder.
		cdq;
		mov ebx, 10;
		idiv ebx;				//eax has Y, from YZ;
		add sum, eax;			//Sum = W+X+Y
		mov leftOver, edx;		//remainder = Z
		add sum, edx;			//Sum 
		//Prepare for division
		mov eax, sum;
		mov ebx, 2;
		cdq;
		idiv ebx;
		mov leftOver, edx;
		//check the remainder.
		cmp edx, 0;
		je itsEven;
		jmp itsOdd;

	itsEven:
		call theEven;		//The Even
		jmp willYouContinue;
	itsOdd:
		call theOdd;		//The odd
		jmp willYouContinue;
	willYouContinue:
		call tryAgain;
		mov al, charChoice; 
		cmp al, 'y';
		je beginCode;
		cmp al, 'n';
		je finale;
	incorrect:
		call wrongChar;
		jmp willYouContinue;
	finale:
		call theEnd;
		
	}
	return 0;
}
