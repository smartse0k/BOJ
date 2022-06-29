#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> moveQueue;

void hanoi(int action, int from, int temp, int to) {
	if(action == 1) {
		moveQueue.push_back(pair<int, int>(from, to));
		return;
	}
	hanoi(action - 1, from, to, temp);
	moveQueue.push_back(pair<int, int>(from, to));
	hanoi(action - 1, temp, from, to);
}

int main(void) {
	cin.sync_with_stdio(false);
	cin.tie(0);

	int input = 0;
	cin >> input;

	hanoi(input, 1, 2, 3);

	cout << moveQueue.size() << "\n";
	for(int i=0; i<moveQueue.size(); i++) {
		cout << moveQueue[i].first << " " << moveQueue[i].second << "\n";
	}

	return 0;
}