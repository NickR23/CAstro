#include <iostream>
#include <cmath>
#include <array>
#include <vector>
#include <limits>
#include "astroMath.h"
using namespace std;

const auto nx = 1280;
const auto ny = 1280;

struct Color { int r; int g; int b;};

void renderCircle(Color** screen) {
	int x, y, r2;
	int radius = 1200;
	r2 = radius * radius;
	screen[nx / 2][(ny / 2) + radius] = {255,0,0};
	screen[nx / 2][(ny / 2) - radius] = {255,0,0};
	screen[(nx / 2) + radius][ny / 2] = {255,0,0};
	screen[(nx / 2) - radius][ny / 2] = {255,0,0};
	y = radius;
  x = 1;
	y = (int) (sqrt(r2 - 1) + 0.5);
	
	while (x < y) {
		screen[(nx / 2) + x][(ny / 2) + y] = {255,0,0};
		screen[(nx / 2) + x][(ny / 2) - y] = {255,0,0};
		screen[(nx / 2) - x][(ny / 2) + y] = {255,0,0};
		screen[(nx / 2) - x][(ny / 2) - y] = {255,0,0};
		screen[(nx / 2) + y][(ny / 2) + x] = {255,0,0};
		screen[(nx / 2) + y][(ny / 2) - x] = {255,0,0};
		screen[(nx / 2) - y][(ny / 2) + x] = {255,0,0};
		screen[(nx / 2) - y][(ny / 2) - x] = {255,0,0};
		x += 1;
		y = (int) (sqrt(r2 - x * x) + 0.5);
	}
}

void drawScreen(Color** screen)	{
	for (auto r = 0; r < nx; r++){
		for (auto c = 0; c < ny; c++){
			Color pixel = screen[r][c];
			cout << pixel.r << " " << pixel.g << " " << pixel.b << endl;
		}
	}
}

void renderStars(Color** screen, vector<Star> stars) {
	for (Star star : stars) {
		//cout << "X: " << star.x << " Y: " << star.y << endl;
		screen[star.x][star.y] = {0, 0, 255};
	}
}

int main(int argc, char** argv) {
	Color **screen = (Color **) malloc(nx * sizeof(Color *));
	for (auto i = 0; i < nx; i++) {
		screen[i] = (Color *)malloc(ny * sizeof(Color));
	}

	cout << "P3" << endl;
	cout << nx << " " << ny << endl;
	cout << "255" << endl;

	vector<Star> stars = readCatalog();
	
	for (auto i = 0; i < stars.size(); i++) {
		Star star = stars.at(i);
		starProjection(star);
		stars.at(i) = star;
	}

	renderStars(screen, stars);
	drawScreen(screen);
}
