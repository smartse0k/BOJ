#include <iostream>

using namespace std;

int incorrect(bool map[], int width, int height, bool test) {
	int ret = 0;
	int mapSize = width * height;

	for(int i=1; i<=mapSize; i++) {
		if(map[i - 1] != test) {
			ret++;
		}

		if(i % width != 0) {
			test = !test;
		}
	}

	return ret;
}

int main(void) {
	cin.sync_with_stdio(false);
	cin.tie(0);

	int width, height;
	cin >> height >> width;

	bool *map = new bool[width * height];
	int idx = 0;

	char *input = new char[width + 1];
	for(int i=0; i<height; i++) {
		cin >> input;
		
		for(int jj=0; jj<width; jj++) {
			map[idx++] = input[jj] == 'W';
		}
	}

	int find1 = incorrect(map, width, height, false);
	int find2 = incorrect(map, width, height, true);

	if(find1 > find2) { 
		//cout << find2;
	} else {
		//cout << find1;
	}

	cout << "find1 = " << find1 << "\n";
	cout << "find2 = " << find2 << "\n";

	delete[] input;
	delete[] map;

	return 0;
}