//Loop Structures
/*
	Thomas Abrahams, Max Krochman
	CS 240
	February 18, 2017
	Question 2: Vowels, Capitalized
*/

#include<iostream>
#include<string>

using namespace std;

char currentChar;
string sentence = "";
short idx = 0;
short mySize = 0;

void captialized()
{
	cout << "Read a sentence with period at the end. Display the sentence so that all vowels are in uppercase." << endl;
	cout << "Sample I/O" << endl;
	cout << "\tEnter a sentence: ";
	getline(cin, sentence);
	cin.ignore();
	mySize = sentence.size();
}
void changeCharacter()
{
	currentChar = sentence[idx];
}
void subCharacter()
{
	sentence[idx] = currentChar;
}
void finished()
{
	cout << "\t\tOutput:" << sentence << endl;
	system("Pause");
}

int main() {
	__asm {
		//+32
		call captialized;
	check:
		
		//If a.
		call changeCharacter;
		mov al, currentChar;		//Gett letter.
		cmp al, 'a';	//cmp al to A
		je changeVowel;
		//If e.
		cmp al, 'e';	//cmp al to A
		je changeVowel;
		//If i
		cmp al, 'i';	//cmp al to A
		je changeVowel;
		//If o
		cmp al, 'o';	//cmp al to A
		je changeVowel;
		//If u
		cmp al, 'u';	//cmp al to A
		je changeVowel;
		//None? Then just increment.
		jmp increment;
	changeVowel:
		sub al, 32;					//Convert to uppercase.
		mov currentChar, al;		//Current character now equals capital.
		call subCharacter;			//The captial is now in the vowel position.		
		jmp increment;				//Increment
	increment:
		inc idx;
		mov ax, idx;		//Mov idx to ax
		cmp ax, mySize;		//Make comparsion to size
		je finale;			//See if you are at the end.
		jmp check;			//If not return to beginning to keep checking.
	finale:
		call finished;


	}


	return 0;
}
