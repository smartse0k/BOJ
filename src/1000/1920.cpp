#include <iostream>
#include <algorithm>
using namespace std;

int cnt;
int input[100001];

int find(int n) {
	int start = 0, end = cnt - 1, middle;

	while (true) {
		if (start > end) {
			return 0;
		}

		middle = (start + end) / 2;
		if (n == input[middle]) {
			return 1;
		} else if (n < input[middle]) {
			end = middle - 1;
		} else if (n > input[middle]) {
			start = middle + 1;
		}
	}
}

int main(void) {
	cin.tie(0);
	cin.sync_with_stdio(false);

	cin >> cnt;

	for (int i = 0; i < cnt; i++) {
		cin >> input[i];
	}

	sort(input, input + cnt);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		cout << find(n) << "\n";
	}

	return 0;
}


/*
#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int, bool> map;

int main(void) {
	cin.tie(0);
	cin.sync_with_stdio(false);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int key;
		cin >> key;

		map.insert({key, true});
	}

	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int key;
		cin >> key;

		unordered_map<int, bool>::iterator it = map.find(key);
		if (it == map.end()) {
			cout << 0 << "\n";
		} else {
			cout << 1 << "\n";
		}
	}

	return 0;
}
*/