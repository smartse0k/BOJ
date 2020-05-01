#include <iostream>

using namespace std;

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	
	for (int row = 1; row <= N * 2; row++) {
		for (int i = 1; i <= N; i++) {
			if (row % 2 == 1) {
				cout << ((i % 2 == 1) ? "*" : " ");
			} else {
				cout << ((i % 2 == 1) ? " " : "*");
			}
		}
		cout << "\n";
	}

	return 0;
}
