/*
Abrahams Thomas
February 7, 2017
CS 240 TTh 2-3:50 PM
Assembly_Three_Digits
*/
#include<iostream>
#include<cstdio>

using namespace std;

int main() {

	int myNum = 0;
	int total = 0;
	bool inputFlag;
	do
	{
		cout << "Enter a three digit number: " ;
		cin >> myNum;
		inputFlag = cin.fail();
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		if (inputFlag)
			cerr << "This answer is not a number" << endl;
		else if (myNum >= 1000)
		{
			cerr << "The number is above 3 digits" << endl;
			inputFlag = true;
		}
		else if (myNum <= 99)
		{
			cerr << "The number does not have 3 digits " << endl;
			inputFlag = true;
		}			

	} while (inputFlag == true);
	__asm {
		mov eax, myNum; //eax = my num
		mov ebx, 100;	//ebx = 100
		cdq;			//Convert eax to quad
		div ebx;		//eax = myNum/100 = X and remainder edx = YZ
		mov ecx, eax;	//ecx = X
		mov eax, edx;	//eax = YZ
		mov ebx, 10;	//ebx = 10;
		cdq;			//Covert eax to quad
		div ebx;		//eax = YZ / 10 = Y and remainder edx = Z
		add ecx, eax;	//ecx = X + Y	
		add ecx, edx;	//ecx = X + Y + Z
		mov total, ecx; //total = ecx
	}
	cout << "\tThe total of digits in " << myNum << " is " << total << endl;
	system("Pause");

	return 0;
}
