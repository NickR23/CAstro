#include <iostream>
#include <cmath>
#include <array>
#include <vector>
#include <limits>
#include "astroMath.h"
#include "imageFormat.h"
using namespace std;

const int radius = 600;

struct Color { int r; int g; int b;};

void renderCircle(Color** screen) {
	int x, y, r2;
	r2 = radius * radius;
	screen[NX / 2][(NY / 2) + radius] = {255,0,0};
	screen[NX / 2][(NY / 2) - radius] = {255,0,0};
	screen[(NX / 2) + radius][NY / 2] = {255,0,0};
	screen[(NX / 2) - radius][NY / 2] = {255,0,0};
	y = radius;
  x = 1;
	y = (int) (sqrt(r2 - 1) + 0.5);
	
	while (x < y) {
		screen[(NX / 2) + x][(NY / 2) + y] = {255,0,0};
		screen[(NX / 2) + x][(NY / 2) - y] = {255,0,0};
		screen[(NX / 2) - x][(NY / 2) + y] = {255,0,0};
		screen[(NX / 2) - x][(NY / 2) - y] = {255,0,0};
		screen[(NX / 2) + y][(NY / 2) + x] = {255,0,0};
		screen[(NX / 2) + y][(NY / 2) - x] = {255,0,0};
		screen[(NX / 2) - y][(NY / 2) + x] = {255,0,0};
		screen[(NX / 2) - y][(NY / 2) - x] = {255,0,0};
		x += 1;
		y = (int) (sqrt(r2 - x * x) + 0.5);
	}
}

void drawScreen(Color** screen)	{
	for (auto r = 0; r < NX; r++){
		for (auto c = 0; c < NY; c++){
			Color pixel = screen[r][c];
			cout << pixel.r << " " << pixel.g << " " << pixel.b << endl;
		}
	}
}

void renderStars(Color** screen, vector<Star> stars) {
	for (Star star : stars) {
		//cout << "X: " << star.x << " Y: " << star.y << endl;
		screen[star.x][star.y] = {255, 255, 255};
	}
}

int main(int argc, char** argv) {
	Color **screen = (Color **) malloc(NX * sizeof(Color *));
	for (auto i = 0; i < NX; i++) {
		screen[i] = (Color *)malloc(NY * sizeof(Color));
	}

	cout << "P3" << endl;
	cout << NX << " " << NY << endl;
	cout << "255" << endl;

	vector<Star> stars = readCatalog();
	double minMag = std::numeric_limits<double>::max();
	double maxMag = std::numeric_limits<double>::min();	
	for (auto i = 0; i < stars.size(); i++) {
		Star star = stars.at(i);
		//cout << "ID: " << star.id << " ";
		starProjection(star);
		//cout << "X: " << star.x << " ";
		//cout << "Y: " << star.y;
		//cout << "MAG: " << star.mag << endl;
		minMag = star.mag < minMag ? star.mag : minMag;
		maxMag = star.mag > maxMag ? star.mag : maxMag;
		stars.at(i) = star;
	}
	//cout << endl << "MinMag: " << minMag << endl;
	//cout << "MaxMag: " << maxMag << endl;

	renderStars(screen, stars);
	renderCircle(screen);
	drawScreen(screen);
}
