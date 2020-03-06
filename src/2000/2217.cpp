#include <iostream>
#include <algorithm>

using namespace std;

short rope[100001];

int main(void) {
	cin.tie(0);
	cin.sync_with_stdio(false);

	int cnt;
	int totalRopeSum = 0;

	cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		cin >> rope[i];
		totalRopeSum += rope[i];
	}

	sort(rope, rope + cnt);

	int avg;
	int maxWeight = 0;
	for (int i = 0; i < cnt; i++) {
		int currentRopeUseCount = cnt - i;
		int tempWeight = 0;
		tempWeight = rope[i] * currentRopeUseCount;
		if (tempWeight > maxWeight) {
			maxWeight = tempWeight;
		}
	}

	cout << maxWeight;

	return 0;
}
