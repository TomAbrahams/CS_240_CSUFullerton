//Loop Structures
/*
	Thomas Abrahams, Max Krochman
	CS 240
	February 18, 2017
	Question 3: Addition, Subtraction
*/
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

char charChoice;
char menuChoice;
int result;
int rand1;
int rand2;
int guess;
int rightAnswers;
int wrongAnswers;

void theMenu()
{
	cout << "------Practice Addition & Subtraction-------------" << endl;
	cout << "a. Practice Addition" << endl;
	cout << "b. Practice Subtraction" << endl;

}
void menuPrompt()
{
	cout << "\tEnter your choice(a/b): ";
	cin >> menuChoice;

}
void random()
{
	//Generation of two random numbers;
	srand(time(NULL)); //Random number.
	rand1 = (rand() % 99) + 1;
	rand2 = (rand() % 99) + 1;

}
void testerAdd()
{
	cout << rand1 << " + " << rand2 << " = ?";
	cin >> guess;
}

void testerSub()
{
	cout << rand1 << " - " << rand2 << " = ?";
	cin >> guess;

}

void doYouContinue()
{
	cout << "Continue(y/n)";
	cin >> charChoice;
}
void score()
{
	cout << "No of CORRECT answers = " << rightAnswers << endl;
	cout << "No of WRONG answers = " << wrongAnswers << endl;
}
void wrong()
{
	cout << "WRONG" << endl;
}
void incorrectChoice()
{
	cout << "Please either choose a or b " << endl;
}
void rightAns()
{
	cout << "CORRECT" << endl;
}
void areYouDone()
{
	cout << "Are you done (y/n)? ";
	cin >> charChoice;
}
void finished()
{
	cout << "Have a nice day" << endl;
	system("pause");
}


int main() {

	__asm {
		//Call menu
		call theMenu;
	menu:		
		mov rightAnswers, 0;	//Initalize Right Answers to zero
		mov wrongAnswers, 0;	//Initialize Wrong Answers to zero
		call menuPrompt;		//Get the menuPrompt
	operation:
		mov al, menuChoice;		//Get the user input either a or b from menu choice
								//Move the input into al.
		cmp al, 'a';			//compare the user input to char a.
		je addition;			//If they are equal jump to procedure addition.
							
		cmp al, 'b';			//compare the user input to char b.
		je subtraction;			//If they are equal jump to procedure subtraction
		call incorrectChoice;	//If they have put an item that is not a or b, then call
								//Incorrect Choice
		jmp menu;				//Jump back to the menu
	addition:				//This is the procedure for addition.
		
		call random;		//Obtain random numbers
		call testerAdd;		//Provide the user with the question and receive the input in guess
		mov eax, guess;		//Move the user's guess into the register.
		mov ebx, rand1;		
		add ebx, rand2;		
		mov result, ebx;	//the result will have the sum of the two random numbers
		cmp eax, result;	//the result will be compared.
		je correct;			//go to procedure correct if the result matches the guess
		jmp incorrect;		//go to procedure incorrect if the result does not match the guess.
	correct:
		call rightAns;			//the right answer function is called to display CORRECT
		inc rightAnswers;		//the variable right answers is incremented by 1
		call doYouContinue;		//the user is asked if they wish to continue.
		cmp charChoice, 'y';	
		je operation;			//if the response is 'y' then we jump to operation
		cmp charChoice, 'Y';	
		je operation;			//if the response is 'Y' then we jump to operation
		cmp charChoice, 'n';	//if the response is 'n' then we jump to operation
		je theScore;
		cmp charChoice, 'N';	//if the response is 'N' then we jump to operation
		je theScore;
	incorrect:
		call wrong;				//the wrong answer function is called to display INCORRECT
		inc wrongAnswers;
		call doYouContinue;		//the function is called asked if you wish to continue
		cmp charChoice, 'y';	//if the response is 'y' then we return to the previous operation.
		je operation;			
		cmp charChoice, 'Y';	//if the response is 'Y' then we return to the previous operation.
		je operation;			
		cmp charChoice, 'n';	//if the response is 'n' then we obtain the score.
		je theScore;
		cmp charChoice, 'N';	//if the response is 'N' then we obtain the score.
		je theScore;
	subtraction:		//This is the procedure for addition.
		call random;		//Obtain random numbers
		call testerSub;		//Provide the user with the question and receive the input in guess
		mov eax, guess;
		mov ebx, rand1;		
		sub ebx, rand2;		
		mov result, ebx;	//the result will have the difference of the two random numbers
		cmp eax, result;	//the result will be compared.
		je correct;			//go to procedure correct if the result matches the guess
		jmp incorrect;		//go to procedure incorrect if the result does not match the guess.

	
	theScore:
		call score;				//Print the final score
		call areYouDone;		//Obtain input to see if the user is done.
		cmp charChoice, 'n';	//If 'n' or 'N' is received then return back to menu procedure
		je menu;
		cmp charChoice, 'N';	
		je menu;
		cmp charChoice, 'Y';	//If 'Y' or 'y' is received then return back to menu procedure
		je finale;
		cmp charChoice, 'y';
		je finale;

	finale:
		call finished;

	}
	return 0;
}
