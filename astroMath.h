#include <iostream>
struct Star {
	std::string id;
	long double ra;
	long double dec;
	int x;
	int y;
};
void starProjection(Star &star);
std::vector<Star> readCatalog();
