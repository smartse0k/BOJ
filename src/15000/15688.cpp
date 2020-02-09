#include <iostream>
#include <queue>

using namespace std;

int *arr;
int cnt;

void input() {
	cin >> cnt;

	arr = new int[cnt];

	int temp;
	for (int i = 0; i < cnt; i++) {
		cin >> temp;
		temp += 2000000;
		arr[i] = temp;
	}
}

void sort() {
	queue<int> *q = new queue<int>[65536];
	const unsigned int CH[] = {0x0000FFFF, 0xFFFF0000};
	const unsigned int SHIFT[] = {0, 16, 32, 64};

	for (unsigned int ch = 0; ch < 2; ch++) {
		for (int i = 0; i < cnt; i++) {
			int pos = (arr[i] & CH[ch]) >> SHIFT[ch];
			q[pos].push(arr[i]);
		}

		int pos = 0;
		for (int i = 0; i < 65536; i++) {
			while (q[i].size() > 0) {
				arr[pos++] = q[i].front();
				q[i].pop();
			}
		}
	}
}

void print() {
	for (int i = 0; i < cnt; i++) {
		cout << (arr[i] - 2000000) << "\n";
	}
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);

	input();
	sort();
	print();

	return 0;
}
