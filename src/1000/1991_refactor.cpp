#include <iostream>
#include <vector>

using namespace std;

unsigned char leftList[100];
unsigned char rightList[100];

void dlr(unsigned char pos) {
	if (pos == 255) return;
	char data = pos + 'A';

	cout << data;
	dlr(leftList[pos]);
	dlr(rightList[pos]);
}

void ldr(unsigned char pos) {
	if (pos == 255) return;
	char data = pos + 'A';

	ldr(leftList[pos]);
	cout << data;
	ldr(rightList[pos]);
}

void lrd(unsigned char pos) {
	if (pos == 255) return;
	char data = pos + 'A';

	lrd(leftList[pos]);
	lrd(rightList[pos]);
	cout << data;
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int lineCount;
	cin >> lineCount;

	for (int i = 0; i < 100; i++) {
		leftList[i] = 255;
		rightList[i] = 255;
	}

	for (int i = 0; i < lineCount; i++) {
		char parent, left, right;
		cin >> parent >> left >> right;
		
		if (left != '.') {
			leftList[parent - 'A'] = left - 'A';
		}

		if (right != '.') {
			rightList[parent - 'A'] = right - 'A';
		}
	}

	dlr(0);
	cout << "\n";
	ldr(0);
	cout << "\n";
	lrd(0);

	return 0;
}
