#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;

int find(int S) {
	const int len = v.size();
	vector<int> picker;
	int count = 0;

	for (int i = 0; i < len; i++) {
		picker.push_back(0);
	}

	for (int i = 0; i < len; i++) {
		picker[len - (i + 1)] = 1;

		do {
			int sum = 0;

			for (int jj = 0; jj < len; jj++) {
				if (picker[jj]) {
					sum += v[jj];
				}
			}
			
			if (sum == S) {
				count++;
			}
		} while (next_permutation(picker.begin(), picker.end()));
	}
	
	
	return count;
}

int main(void) {
	int N, S;
	cin >> N >> S;

	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		v.push_back(temp);
	}

	int result = find(S);
	cout << result;

	return 0;
}
