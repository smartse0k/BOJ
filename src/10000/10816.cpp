#include <iostream>

using namespace std;

int cnt;
unsigned int arr[20000002] = { 0, };

int main(void) {
	cin.tie(0);
	cin.sync_with_stdio(false);

	cin >> cnt;

	for (int i = 0; i < cnt; i++) {
		int v;
		cin >> v;
		arr[v + 10000000]++;
	}

	cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		int v;
		cin >> v;
		cout << arr[v + 10000000] << " ";
	}

	return 0;
}