#include <iostream>

using namespace std;

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	for (int row = 1; row <= N; row++) {
		for (int i = 1; i <= row; i++) {
			cout << '*';
		}
		cout << "\n";
	}
	for (int row = N - 1; row >= 1; row--) {
		for (int i = 1; i <= row; i++) {
			cout << '*';
		}
		cout << "\n";
	}
	
	return 0;
}
