#include <iostream>

using namespace std;

int main(void) {
	int cnt;
	int M, N, x, y;

	cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		cin >> M >> N >> x >> y;

		if (x == M) {
			x = 0;
		}
		if (y == N) {
			y = 0;
		}

		int year = x;
		int answer = -1;
		while (year <= M * N) {
			int calc = year % N;
			if (calc == y) {
				answer = calc;
				break;
			}
			year += M;
		}

		if (answer == -1) {
			cout << -1 << "\n";
		} else {
			cout << year << "\n";
		}
	}

	return 0;
}