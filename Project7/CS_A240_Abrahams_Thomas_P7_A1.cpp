#include<iostream>
#include<iomanip>

using namespace std;

float a =0.0, b=0.0, c=0.0, h = 0.0;
float theLength = 0.0, width = 0.0;
float half = 0.5;
float two = 2;
float triangleArea;
float trianglePerimeter;
float rectangleArea;
float rectanglePerimeter;
void askValue()
{
	cout << "Enter the values of a,b,c and h for the triangle: ";
	cin >> a >> b >> c >> h;
	cout << endl;
	cout << "Enter the length and the width of the triangle: ";
	cin >> theLength >> width;

}
void results()
{
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	cout << "Triangle" << endl;
	cout << "\tArea......................." << triangleArea << endl;
	cout << "\tPerimeter.................." << trianglePerimeter<< endl;
	
	cout << "Rectangle" << endl;
	cout << "\tArea......................." << rectangleArea << endl;
	cout << "\tPerimeter.................." << rectanglePerimeter << endl;
	system("Pause");
}





int main() {
	__asm {
	//Call the menu
	callMenu:
		call askValue;
	//Find the area of a triangle
	findAreaTriangle:
		//0.5*h*c = 0.5h*c*
		fld half;	//stack = 0.5
		fld h;		//stack = h,0.5
		fmul;		//stack = h*0.5
		fld c;		//stack = c, h*0.5
		fmul;		//stack	= c*h*0.5
		fstp triangleArea;	//area = c*h*0.5
	//Find the perimeter of a triangle
	findPerimeterTriangle:
		//a+b+C= ab+c+
		fld a;		//stack = a
		fld b;		//stack = b,a
		fadd;		//stack = a+b
		fld c;		//stack = c, a+b
		fadd;		//stack = c+a+b
		fstp trianglePerimeter;
	//Find the area of a rectangle
	findAreaRectangle:
		//l*w = lw*
		fld theLength;
		fld width;
		fmul;			//lw*
		fstp rectangleArea;
	//Find the perimeter of a rectangle
	findPerimeterRectangle:
		//2*l+2*w= 2l*2w*+
		fld two;
		fld width;
		fmul;
		fld two;
		fld theLength;
		fmul;
		fadd;
		fstp rectanglePerimeter;
	theEnd:
		call results;

	//Call the results
	}
	return 0;
}
