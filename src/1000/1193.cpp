#include <iostream>

using namespace std;

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0);

	int input;
	cin >> input;

	bool isLeftBig = false;
	int line = 1;
	int lineMax = 1;
	int add = 2;

	while (input > lineMax) {
		line++;
		isLeftBig = !isLeftBig;
		lineMax += add;
		add++;
	}

	int distance = lineMax - input;
	int posLeft, posRight;

	if(isLeftBig) {
		posLeft = line - distance;
		posRight = distance + 1;
	} else {
		posRight = line - distance;
		posLeft = distance + 1;
	}

	cout << posLeft << "/" << posRight;

	return 0;
}