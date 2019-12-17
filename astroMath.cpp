#include <iostream>
#include <cmath>
using namespace std;

#define PI 3.14159265

void starProjection(float ra, float dec) {
	ra = ra * PI / 180;
	dec = dec * PI / 180;	
	float x = cos(dec) * sin(ra);
	float y = sin(dec);
	float z = cos(dec) * cos(ra);
	
	float xProj = x / (1.0 + z);
	float yProj = y / (1.0 + z);	
	
	cout << "x'  " << x << endl;
	cout << "y'  " << y << endl;
	cout << "z'  " << z << endl;
	cout << endl << "X  " << xProj << endl;
	cout << "Y  " << yProj << endl;
}	
