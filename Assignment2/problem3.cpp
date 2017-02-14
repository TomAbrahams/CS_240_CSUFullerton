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
void kidwarn()
{
	cout << "You are a kid. No membership for you" << endl;

}

int main()
{
	__asm {
		//gender, age,
		//Determine gender
		call menu; //Menu gets variables.
		mov ax, gender; //ax = gender
		cmp ax, male;
		je male:
	female:
		mov ax, age; //ax = age
		cmp ax, 20; //
		jge femaleTwenty;
		jmp female13to19;
	femaleTwenty:
		//20 years old female.
		mov total, 80;
		jmp endgame;
	female13to19:
		mov ax, age;
		cmp ax, age;
		jl kid;
		mov total, 85;
		jmp endgame;
	male:
		mov ax, age; //ax = age 
		cmp ax, 20;
		jge maleTwenty;
		jmp maleLessTwenty;
	kid:
		call kidWarn;
		jmp finish;
	finish:



	endgame:

	}
}
