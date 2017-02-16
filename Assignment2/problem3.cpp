/*
	Abrahams, Thomas
	Partner: Max Krochman
	CS 240 
	Project 3 Division, Multiplication, and Making Decisions
	Part 3: The Club
*/
#include<iostream>
#include<cstdio>

using namespace std;
short adultMalePrice = 100;
short teenMalePrice = 75;
short adultFemPrice = 80;
short teenFemPrice = 85;
short age = 0;
short gender = (short)'M';
short total= 0;
short male = (short)'M';
short female = (short)'F';

void menu()
{
	cout << "---------------ACE CLUB---------------" << endl;
	cout << "Male" << endl;
	cout << "\tAdult(age>19)......................." << endl;
	cout << "\tTeenager(age 13-19)................." << endl;
	cout << "Female" << endl;
	cout << "\tAdult(age>19)......................." << endl;
	cout << "\tTeenager(age 13-19)................." << endl;
	cout << "How old are you? ";
	cin >> age;
	cout << "What is your gender (M/F)? " << endl;
	char myGender;
	cin >> myGender;
	//Convert
	myGender = toupper(myGender);
	gender = (short)myGender;


}
void thankyou()
{
	cout << "Your membership is $" << total << endl;

}
void kidWarn()
{
	cout << "You are a kid. No membership for you" << endl;

}
void theEnd()
{
	cout << "Thank you for your time." << endl;
	system("Pause");
}

int main()
{
	cout << male;
	cout << "Hello noggers" << endl;
	
	__asm {
		//gender, age,
		//Determine gender
		call menu; //Menu gets variables.
		mov ax, gender; //ax = gender
		cmp ax, male;
		je male1;
	female1:
		mov ax, age; //ax = age
		cmp ax, 20; //
		jge femaleTwenty;
		cmp ax, 13;
		jge female13to19;
		jmp kid;
	femaleTwenty:
		//20 years old female.
		mov total, 80;
		jmp finish;
	female13to19:
		mov ax, age;
		mov total, 85;
		jmp finish;
	male1:
		mov ax, age; //ax = age
		cmp ax, 20; //
		jge maleTwenty;
		cmp ax, 13;
		jge male13to19;
		jmp kid;
	maleTwenty:
		//20 years old female.
		mov total, 100;
		jmp finish;
	male13to19:
		mov ax, age;
		mov total, 75;
		jmp finish;		
	kid:
		call kidWarn;
		jmp endgame;

	finish:
		call thankyou;

	endgame:
		call theEnd;
	}
	
	return 0;
}
