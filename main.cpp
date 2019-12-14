#include <iostream>
#include <array>
#include <vector>
using namespace std;


const auto nx = 1280;
const auto ny = 1280;

struct Coords { int x; int y;};
struct Color { int r; int g; int b;};
struct Star {
	int x;
	int y;
	int size;
};

bool isInStarMap(int x, int y, vector<Star> stars) {
	for (Star currentStar : stars) {
		if (currentStar.x == x && currentStar.y == y) {
			return true;
		}
	}
	return false;
}

void renderStars(Color** screen, vector<Star> stars) {
	for (Star currentStar: stars) {
		screen[currentStar.x][currentStar.y] = { 255, 0, 0};
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
	
	vector<Star> stars;
	stars.push_back({3,4});		
	stars.push_back({7, 5});	
	
//	renderStars(screen, stars);	
	cout << "P3" << endl;
	cout << nx << " " << ny << endl;
	cout << "255" << endl;
		
		
	for (int x = 0; x < nx; x++) {
		for (int y = 0; y < ny; y++) {
		
			float cx = float(x) / float(nx);
			float cy = float(y) / float(ny);

			cx *= 254.9;
			cy *= 254.9;
			screen[x][y] = {(int)cx, (int)cy};	
			//cout << int(cx) << " " << int(cy) << " " << 250 << endl;	
		}
	}
	
	drawScreen(screen);
	return 0;
}
