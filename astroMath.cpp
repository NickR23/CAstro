#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>
#define PI 3.14159265

struct Star {
	std::string id;
	float ra;
	float dec;
};

/**
 * Gets a string from a byte range.
 */
std::string gsfb(char * s, int begin, int end) {
	std::string stringFromBytes;
	for (auto i = begin; i < end; i++ ) {
		stringFromBytes += s[i];
	}
	return stringFromBytes;
}

void parseLine(char * buffer) {
	Star star = {};
	// get  id
	std::string idString = gsfb(buffer, 1, 6);
	star.id = idString;
	std::cout << "ID: " << star.id  << " ";
	// get right ascension
	std::string raString = gsfb(buffer, 16, 28);
	star.ra = std::stof(raString);
	std::cout << "RA: " << star.ra << " ";
	// get declination	
	std::string decString = gsfb(buffer, 30, 42);
	star.dec = std::stof(decString);
	std::cout << "DEC: " << star.dec << std::endl;	
}

void readCatalog() {
	std::ifstream is("./data/test.dat", std::ifstream::binary);
	int length = 0;
	if (is) {
		is.seekg(0, is.end);
		length = is.tellg();
		is.seekg(0, is.beg);
	
		char * buffer = new char [276];

		is.read (buffer, 276);
		is.close();
		
		parseLine(buffer);
		delete[] buffer;
	}
}

void starProjection(float ra, float dec) {
	ra = ra * PI / 180;
	dec = dec * PI / 180;	
	float x = cos(dec) * sin(ra);
	float y = sin(dec);
	float z = cos(dec) * cos(ra);
	
	float xProj = x / (1.0 + z);
	float yProj = y / (1.0 + z);	
	
	std::cout << "x'  " << x << std::endl;
	std::cout << "y'  " << y << std::endl;
	std::cout << "z'  " << z << std::endl;
	std::cout << std::endl << "X  " << xProj << std::endl;
	std::cout << "Y  " << yProj << std::endl;
}	
