#include <iostream>

using namespace std;

bool map[10000][10000];
int inputSize = 0;

void printMap() {
	for(int y=0; y<inputSize; y++) {
		for(int x=0; x<inputSize; x++) {
			if(map[y][x]) {
				cout << "*";
			} else {
				cout << " ";
			}
		}
		cout << "\n";
	}
}

void fillMap(int cSize, int fillX, int fillY) {
	if(cSize == 3) {
		map[fillY + 0][fillX + 0] = true;
		map[fillY + 0][fillX + 1] = true;
		map[fillY + 0][fillX + 2] = true;

		map[fillY + 1][fillX + 0] = true;
		map[fillY + 1][fillX + 2] = true;

		map[fillY + 2][fillX + 0] = true;
		map[fillY + 2][fillX + 1] = true;
		map[fillY + 2][fillX + 2] = true;

		return;
	} else {
		for(int i=0; i<9; i++) {
			int addX = (cSize / 3) * (i % 3);
			int addY = (cSize / 3) * (i / 3);

			if(i != 4) {
				fillMap(cSize / 3, fillX + addX, fillY + addY);
			}
		}
	}
}

int main(void) {
	cin.sync_with_stdio(false);
	cin.tie(0);

	cin >> inputSize;

	fillMap(inputSize, 0, 0);

	printMap();

	return 0;
}