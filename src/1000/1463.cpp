#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

void buildMin(int num) {
	v.push_back(-1); // 0
	v.push_back(0); // 1
	v.push_back(1); // 2
	v.push_back(1); // 3

	if (num <= 3) {
		return;
	}

	for (int i = 4; i <= num; i++) {
		int currentMin = 0x7FFFFFFF;
		int current = 0x7FFFFFFF;

		// 1) X가 3으로 나누어 떨어지면, 3으로 나눈다.
		if (i % 3 == 0) {
			current = v[i / 3] + 1;
			if (currentMin >= current) {
				currentMin = current;
			}
		}

		// 2) X가 2로 나누어 떨어지면, 2로 나눈다.
		if (i % 2 == 0) {
			current = v[i / 2] + 1;
			if (currentMin >= current) {
				currentMin = current;
			}
		}

		// 3) 1을 뺀다.
		current = v[i - 1] + 1;
		if (currentMin >= current) {
			currentMin = current;
		}

		v.push_back(currentMin);
	}
}

int main() {
	int input;
	cin >> input;

	buildMin(input);
	cout << v[input];
		
	return 0;
}
