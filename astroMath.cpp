#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>
#include "astroMath.h"
#define PI 3.14159265

Star parseLine(std::string buffer) {
	Star star = {};
	// get  id
	std::string idString = buffer.substr(0,6);
	star.id = idString;
	
	// get right ascension
	std::string raString = buffer.substr(15,13);
	star.ra = std::stold(raString);
	
	// get declination	
	std::string decString = buffer.substr(29, 13);
	star.dec = std::stold(decString);
	
	return star;
}

std::vector<Star> readCatalog() {
	std::ifstream is("./data/hip2.dat", std::ifstream::binary);
	std::string bf;
	std::vector<Star> stars;
	while (std::getline(is, bf) ){
		stars.push_back(parseLine(bf));
	}
	is.close();
	return stars;	
}


void starProjection(Star &star) {
	float ra = star.ra * PI / 180;
	float dec = star.dec * PI / 180;	
	float x = cos(dec) * sin(ra);
	float y = sin(dec);
	float z = cos(dec) * cos(ra);
	
	float xProj = x / (1.0 + z);
	float yProj = y / (1.0 + z);	
	
	double minDec = -1.567;
	double maxDec = 1.56328;
	double minRa = 1.59148e-05;
	double maxRa = 6.28282;
	double normX = (star.dec - (minDec)) / (maxDec - (minDec));
	normX *= 1279;
	double normY = (star.ra - (minRa)) / (maxRa - (minRa));
	normY *= 1279;
	star.x = normX;
	star.y = normY;
}	
