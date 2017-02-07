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
		if (myNum >= 1000)
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
		//Find digit 1
		sub edx, edx; //Zero edx
		mov eax, myNum; //eax = my num
		mov ebx, 100; //ebx = 100
		div ebx; //eax = myNum/100 = X and remainder edx = YZ
		mov ecx, eax; //ecx = X
		mov eax, edx; // eax = YZ
		//Zero edx
		sub edx, edx;	//edx = 0;
		mov ebx, 10;	//ebx = 10;
		div ebx;		//eax = YZ / 10 = Y and remainder edx = Z
		add ecx, eax;  //ecx = X + Y
		//Zero edx
		add ecx, edx;  //ecx = X + Y + Z
		mov total, ecx; //total = ecx
	}

	cout << "\tThe total of digits in " << myNum << " is " << total << endl;
	system("Pause");

	return 0;
}
