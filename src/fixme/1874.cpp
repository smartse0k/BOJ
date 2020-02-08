#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0);

	stack<int> stack;
	queue<char> queue;

	int N;
	cin >> N;

	int next = 1;
	bool error = false;
	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;

		// push
		while (input >= next) {
			stack.push(next++);
			queue.push('+');
		}

		// pop
		while (true) {
			int top = stack.top();

			if (stack.empty()) {
				error = true;
				break;
			}

			stack.pop();
			queue.push('-');

			if (input == top) {
				break;
			}
		}
	}

	if (error) {
		cout << "NO";
	} else {
		while (!queue.empty()) {
			cout << queue.front() << "\n";
			queue.pop();
		}
	}

	return 0;
}