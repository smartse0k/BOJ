#include <iostream>
#include <vector>

using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);

	int count[2], temp;
	cin >> count[0] >> count[1];

	vector<int> arr[2];
	int pos[2];
	pos[0] = pos[1] = 0;

	for (int idx = 0; idx < 2; idx++) {
		for (int i = 0; i < count[idx]; i++) {
			cin >> temp;
			arr[idx].push_back(temp);
		}
	}

	for (;;) {
		bool isOver1 = arr[0].size() <= pos[0];
		bool isOver2 = arr[1].size() <= pos[1];

		if (isOver1 && isOver2) {
			break;
		} else if (isOver1) {
			cout << arr[1][pos[1]++];
		} else if (isOver2) {
			cout << arr[0][pos[0]++];
		} else {
			if (arr[0][pos[0]] < arr[1][pos[1]]) {
				cout << arr[0][pos[0]++];
			}
			else {
				cout << arr[1][pos[1]++];
			}
		}
		
		cout << " ";
	}

	return 0;
}
