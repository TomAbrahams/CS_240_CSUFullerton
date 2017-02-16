/*
	Max Krochman
	Partner: Abrahams, Thomas
	CS 240 
	Project 3 Division, Multiplication, and Making Decisions
	Part 2: Computing Averages
*/

#include<iostream>

using namespace std;

int theScore;
int theTotalScore;
int theCount;
int theAverage;

void display()
{
	cout << "Let's computer your score's average:" << endl;
}

void score()
{
	cout << "Enter your score (-1 to stop): ";
	cin >> theScore;
}
void displayAverage()
{
	cout << "\t\tYour average is " << theAverage << endl;
	system("Pause");
}

int main() {

	__asm {
		call display; //Display called "Let's compute your score's average:"
	getScore:
		call score;
		mov eax, theScore;			//eax = theScore
		cmp theScore, -1;		//Check if the score is -1
		je endgame;					//If the score equals -1 then get to endgame
		add theTotalScore, eax;		//theTotalScore = eax
		inc theCount;				//theCount++
		jmp getScore;				//Go back to the score
	endgame:
		mov eax, theTotalScore;		//Total score
		mov ebx, theCount;			//The count
		cdq;						//Get ready for division
		idiv ebx;					//Divide eax by ebx. eax/ebx store in eax, remainder in edx
		mov theAverage, eax;		//The average = eax.
		call displayAverage;		//Call display average

	}

	return 0;
}
