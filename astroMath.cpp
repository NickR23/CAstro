#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>
#include "astroMath.h"
#include "imageFormat.h"
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
	
	// get magnitude
	std::string magnitude = buffer.substr(129, 7);
	double dMag = std::stod(magnitude);
	dMag = (dMag - (-1.0876)) / (14.5622 - (-1.0876));

	star.mag = dMag;
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

void stereographProjection(Star &star, float radius) {
	float centralRa = -78.638176 * PI / 180;
	float centralDec = 35.779591 * PI / 180;
	long double k = sqrt((radius * 2) / (1 + sin(centralDec) * sin(star.dec) 
																		+ cos(centralDec) * cos(star.dec) * cos(star.ra - centralRa)));

	long double projX = k * cos(star.dec) * sin(star.ra - centralRa);

	long double projY = k * (cos(centralDec)*sin(star.dec) 
											- sin(centralDec) * cos(star.dec) * cos(star.ra - centralRa));

	double minX = (NX / 2) - radius;
	double maxX = (NX / 2) + radius;
	double minY = (NY / 2) - radius;
	double maxY = (NY / 2) + radius;
	double normX = (projX - minX) / (maxX - minX);
	double normY = (projY - minY) / (maxY - minY);
	normX += NX / 2;
	normY += NY / 2;
	star.x = normX;
	star.y = normY;
}

void starProjection(Star &star) {
	
	double minDec = -1.567;
	double maxDec = 1.56328;
	double minRa = 1.59148e-05;
	double maxRa = 6.28282;
	double normX = (star.dec - (minDec)) / (maxDec - (minDec));
	normX *= NX - 1;
	double normY = (star.ra - (minRa)) / (maxRa - (minRa));
	normY *= NY - 1;
	star.x = normX;
	star.y = normY;
}	
