#include <iostream>
#include <cmath>

using namespace std;

void findData(int N, int &x, int &y, int &num, int &r, int &c, int &endFlag, int &origN) {
	if(N == 1) {
		if(x == c && y == r) {
			cout << num;
			endFlag = 1;
		}

		if(x + 1 == c && y == r) {
			cout << num + 1;
			endFlag = 1;
		}

		if(x == c && y + 1 == r) {
			cout << num + 2;
			endFlag = 1;
		}

		if(x + 1 == c && y + 1 == r) {
			cout << num + 3;
			endFlag = 1;
		}

		x++;
		y++;
		num += 4;
	} else {
		int width = 1;
		int addNum = 1;
		for(int i=0; i<N; i++) {
			width *= 2;
			addNum *= 4;
		}
		addNum /= 4;
	
		if(x <= c && c <= x + width / 2 - 1 && y <= r && r <= y + width / 2 - 1) {
			findData(N - 1, x, y, num, r, c, endFlag, origN);
			if(endFlag == 1) {
				return;
			}
			x += 1;
			y -= (pow((double)2, (double)N) / 2) - 1;
		} else {
			x += width / 2;
			num += addNum;
		}

		if(x <= c && c <= x + width / 2 - 1 && y <= r && r <= y + width / 2 - 1) {
			findData(N - 1, x, y, num, r, c, endFlag, origN);
			if(endFlag == 1) {
				return;
			}
			x -= (pow((double)2, (double)N)) - 1;
			y += 1;
		} else {
			x -= width / 2;
			y += width / 2;
			num += addNum;
		}
		
		if(x <= c && c <= x + width / 2 - 1 && y <= r && r <= y + width / 2 - 1) {
			findData(N - 1, x, y, num, r, c, endFlag, origN);
			if(endFlag == 1) {
				return;
			}
			x += 1;
			y -= (pow((double)2, (double)N) / 2) - 1;
		} else {
			x += width / 2;
			num += addNum;
		}
		
		findData(N - 1, x, y, num, r, c, endFlag, origN);
		if(endFlag == 1) {
			return;
		}
	}
}

int main(void) {
	int N, r, c;
	cin >> N >> r >> c;

	/*
	long long totalCell = 1;
	for(int i=0; i<N; i++) {
		totalCell *= 4;
	}
	cout << "ÀüÃ¼ ¼¿ °³¼ö = " << totalCell << "\n";
	*/

	int x = 0, y = 0;
	int num = 0;
	int endFlag = 0;
	findData(N, x, y, num, r, c, endFlag, N);
	
	return 0;
}