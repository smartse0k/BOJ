#include <iostream>

using namespace std;

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	int space = 0;
	for (int row = N * 2 - 1; row >= 1; row -= 2) {
		for (int i = 0; i < space; i++) {
			cout << ' ';
		}
		for (int i = 1; i <= row; i++) {
			cout << '*';
		}
		space++;
		cout << "\n";
	}

	space -= 2;
	for (int row = 3; row <= N * 2 - 1; row += 2) {
		for (int i = 0; i < space; i++) {
			cout << ' ';
		}
		for (int i = 1; i <= row; i++) {
			cout << '*';
		}
		space--;
		cout << "\n";
	}
	

	return 0;
}
