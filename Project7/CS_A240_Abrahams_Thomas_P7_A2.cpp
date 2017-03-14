#include<iostream>
#include<iomanip>

using namespace std;

float a;
float b;
float c;
float four = 4.0;
float negOne = -1.0;
float two = 2.0;
float xOne;
float xTwo;

void getRoots()
{
	cout << "To see the two real roots of aX^2 +bX +c = 0, \nenter the a,b, and c values: ";
	cin >> a >> b >> c;
}
void results()
{
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	cout << "\tX1 = " << xOne << " X2 = " << xTwo << endl;
	system("pause");
}
int main() {
	__asm {
		//Get roots
	getTheRoots:
		call getRoots;
		
	resultsCalculation:	//Calculate the results
		//(-b+sqrt(b^2-4ac)) / (2a) = bb*4a*c-*sqrt b+ 2a*/
		fld b;		//stack = b
		fld b;		//stack = b, b
		fmul;		//stack = b*b
		fld four;	//stack = 4, b*b
		fld a;		//stack = a, 4, b^2
		fmul;		//stack	= 4a, b^2
		fld c;		//stack = c, 4a, b^2
		fmul;		//stack = 4ac, b^2
		fsub;		//stack = b^2-4ac
		fsqrt;		//stack = sqrt(b^2-4ac)
		fld b;		//stack = b, sqrt(b^2-4ac)
		fsub;		//stack = -b+sqrt(b^2-4ac)
		fld two;	//stack = 2, -b+sqrt(b^2-4ac)
		fld a;		//stack = a,2,-b+sqrt(b^2-4ac)
		fmul;		//stack = 2a, -b+sqrt(b^2-4ac)
		fdiv;		//stack = (-b+sqrt(b^2-4ac))/2a
		fstp xOne;
		//b+sqrt(b^2-4ac) / (2a) = bb*4a*c*sqrt 2a*/ b+
	resultsDisplayed: //Display results
		fld b;		//stack = b
		fld b;		//stack = b, b
		fmul;		//stack = b*b
		fld four;	//stack = 4, b*b
		fld a;		//stack = a, 4, b^2
		fmul;		//stack	= 4a, b^2
		fld c;		//stack = c, 4a, b^2
		fmul;		//stack = 4ac, b^2
		fsub;		//stack = b^2-4ac
		fsqrt;		//stack = sqrt(b^2-4ac)
		fld b;		//stack = b, sqrt(b^2-4ac)
		fadd;		//stack = b+sqrt(b^2-4ac)
		fld two;	//stack = 2, -b+sqrt(b^2-4ac)
		fld a;		//stack = a,2,-b+sqrt(b^2-4ac)
		fmul;		//stack = 2a, -b+sqrt(b^2-4ac)
		fdiv;		//stack = (-b+sqrt(b^2-4ac))/2a
		fstp xTwo;
	theEnd:
		call results;

	}
	return 0;
}
