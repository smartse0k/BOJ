#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

void compress(char **data, int range, int cx, int cy) {
	if(range == 1) {
		cout << data[cy][cx];
		return;
	}

	long long check = 0;
	for(int y=0; y<range; y++) {
		for(int x=0; x<range; x++) {
			check += (data[cy + y][cx + x] - '0');
		}
	}

	if(check == 0) {
		cout << "0";
	} else if(check == range*range) {
		cout << "1";
	} else {
		int half = range / 2;
		cout << "(";
		compress(data, half, cx, cy);
		compress(data, half, cx + half, cy);
		compress(data, half, cx, cy + half);
		compress(data, half, cx + half, cy + half);
		cout << ")";
	}
}

int main(void) {
	cin.sync_with_stdio(false);
	cin.tie(0);

	int num;
	cin >> num;

	char **data = new char*[num + 1];
	char *input = new char[num + 1];

	for(int i=0; i<num; i++) {
		cin >> input;

		data[i] = new char[num + 1];
		strcpy(data[i], input);
	}

	compress(data, num, 0, 0);

	return 0;
}