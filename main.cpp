#include <iostream>
#include <cmath>
#include <array>
#include <vector>
using namespace std;


const auto nx = 2440;
const auto ny = 2440;

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

int main(int argc, char** argv) {
	//Initiallize screen
	Color **screen = (Color **) malloc(nx * sizeof(Color *));
	for (auto i = 0; i < nx; i++) {
		screen[i] = (Color *)malloc(ny * sizeof(Color));
	}	
	
	cout << "P3" << endl;
	cout << nx << " " << ny << endl;
	cout << "255" << endl;
		
		
	for (int x = 0; x < nx; x++) {
		for (int y = 0; y < ny; y++) {
		
			float cx = float(x) / float(nx);
			float cy = float(y) / float(ny);

			cx *= 254.9;
			cy *= 254.9;
			screen[x][y] = {0, 0, 0};	
		}
	}
	renderCircle(screen);	
	drawScreen(screen);
	return 0;
}
