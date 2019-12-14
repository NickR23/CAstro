#include <iostream>
#include <cmath>
using namespace std;

void starProjection(float ra, float dec) {
	float x = cos(ra) * sin(dec);
	float y = sin(ra);
	float z = cos(ra) * cos(dec);
	
	float xProj = x / (1.0 + z);
	float yProj = y / (1.0 + z);	
	
	cout << "x'  " << x << endl;
	cout << "y'  " << y << endl;
	cout << "z'  " << z << endl;
	cout << endl << "X  " << xProj << endl;
	cout << "Y  " << yProj << endl;
}	
