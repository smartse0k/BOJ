#include <iostream>

using namespace std;

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int X, Y;
	cin >> X >> Y;

	if (X > 0) {
		if (Y > 0) {
			cout << 1;
		} else {
			cout << 4;
		}
	} else {
		if (Y > 0) {
			cout << 2;
		} else {
			cout << 3;
		}
	}

	return 0;
}
