#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	if (N == 1) {
		return 0;
	}

	int CN = N;

	while (CN > 1) {
		int NN = sqrt(CN);
		bool find = false;

		for (int i = 2; i <= NN; i++) {
			if (CN % i == 0) {
				cout << i << endl;
				CN /= i;
				find = true;
				break;
			}
		}

		if (!find) {
			break;
		}
	}

	if (N == CN) {
		cout << N;
	} else {
		if (CN > 1) {
			cout << CN;
		}
	}
	
	return 0;
}
