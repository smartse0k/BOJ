#include <iostream>

using namespace std;

bool map[4000][8000];
int inputSize = 0;

void printMap() {
	for(int y=0; y<inputSize; y++) {
		for(int x=0; x<inputSize*2; x++) {
			if(map[y][x]) {
				cout << "*";
			} else {
				cout << " ";
			}
		}
		cout << "\n";
	}
}

void fillMap(int cSize, int startX, int startY) {
	if(cSize == 3) {
		map[startY + 0][startX + 0] = true;

		map[startY + 1][startX - 1] = true;
		map[startY + 1][startX + 1] = true;

		map[startY + 2][startX - 2] = true;
		map[startY + 2][startX - 1] = true;
		map[startY + 2][startX + 0] = true;
		map[startY + 2][startX + 1] = true;
		map[startY + 2][startX + 2] = true;

		return;
	} else {
		fillMap(cSize / 2, startX, startY);
		fillMap(cSize / 2, startX - cSize / 2, startY + cSize / 2);
		fillMap(cSize / 2, startX + cSize / 2, startY + cSize / 2);
	}
}

int main(void) {
	cin.sync_with_stdio(false);
	cin.tie(0);

	cin >> inputSize;

	fillMap(inputSize, inputSize - 1, 0);

	printMap();

	return 0;
}