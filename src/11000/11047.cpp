#include <iostream>
#include <utility>

using namespace std;

int coinCount;
int target;
pair<int, int> coin[11];
int result;

int main(void) {
	cin >> coinCount >> target;

	for (int i = 1; i <= 10; i++) {
		cin >> coin[i].first;
	}

	for (int i = 10; i >= 1; i--) {
		if (coin[i].first > target || coin[i].first <= 0) {
			continue;
		}

		coin[i].second = target / coin[i].first;
		target = target % coin[i].first;

		result += coin[i].second;

		if (target == 0) {
			break;
		}
	}

	cout << result;

	return 0;
}