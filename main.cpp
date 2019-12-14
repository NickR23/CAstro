#include <iostream>
#include <array>
#include <vector>
using namespace std;

struct coords { int x; int y;};

struct star {
	int x;
	int y;
	int size;
};

bool isInStarMap(int x, int y, vector<star> stars) {
	for (star currentStar : stars) {
		if (currentStar.x == x && currentStar.y == y) {
			return true;
		}
	}
	return false;
}

struct pixel {
	struct coords point; int color;
}; 

int main(int argc, char** argv) {
	//Initiallize screen
	vector<vector<pixel>> screen;	
	int nx = 1280;
	int ny = 1280;
	vector<star> stars;
	stars.push_back({10,10});		
	stars.push_back({30, 20});	
	
	cout << "P3" << endl;
	cout << nx << " " << ny << endl;
	cout << "255" << endl;
	
	for (int x = 0; x < nx; x++) {
		for (int y = 0; y < ny; y++) {
			
			if (isInStarMap(x, y, stars)) {
					cout << 255 << " " << 255 << " " << 255 << endl;	
			}
			else{	
				float cx = float(x) / float(nx);
				float cy = float(y) / float(ny);

				cx *= 254.9;
				cy *= 254.9;
			
				cout << 0 << " " << 0 << " " << 0 << endl;	
				//cout << int(cx) << " ";
				//cout << int(cy) << " ";
				//cout << "200" << endl;		
			}	
		}
	}
	return 0;
}
