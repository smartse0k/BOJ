#include <iostream>
#include <queue>

using namespace std;

int cnt;

struct compare {
	bool operator()(const int& _Left, const int& _Right) const
	{
		return (_Left > _Right);
	}
};

priority_queue<int, vector<int>, compare> q;

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		int input;
		cin >> input;

		if (input == 0) {
			if (q.empty()) {
				cout << "0\n";
			} else {
				cout << q.top() << "\n";
				q.pop();
			}
		} else {
			q.push(input);
		}
	}

	return 0;
}