#include <iostream>

using namespace std;
int a[5] = { 9,3,22,8,1 };
int n = 5;
int nMinusOne = 4;
int i = 0;
int j = 0;
int counter;
int currentValue;
void theEnd()
{
	cout << endl;
	system("pause");
}
void printItem()
{
	cout << currentValue << " " ;
}

int main()
{
	__asm {

	forLoop1:
		mov j, -1;
	incrementJ:
		inc j;
		mov ecx, n;
		sub ecx, i;
		sub ecx, 1;
		cmp j, ecx;
		jge incrementI;
		jmp swaper;

	incrementI:
		inc i;
		mov edx, i;
		cmp edx, nMinusOne;
		jge finale;
		jmp forLoop1;
	swaper:
		mov edx, j;
		mov eax, [a + 4 * edx];
		add edx, 1;
		mov ebx, [a + 4 * edx];
		cmp eax, ebx;
		jg performSwap;
		jmp incrementJ;
	performSwap:
		mov edx, j;
		mov [a + 4* edx], ebx;
		add edx, 1;
		mov [a + 4 * edx], eax;
		jmp incrementJ;
	finale:
		mov counter, -1;
		mov n, 4;
	printTheArray:
		inc counter;		//counter = 0
		mov edx, counter;
		mov eax, [a + 4 * edx];
		mov currentValue, eax;
		call printItem;
		mov edx, counter;
		cmp edx, n;
		jl printTheArray;
		call theEnd;
		 

		
	}
	return 0;
}
