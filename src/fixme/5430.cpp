#include <iostream>
#include <stack>
#include <deque>
#include <string>
#include <string.h>

using namespace std;

#pragma warning(disable: 4996)

deque<char*> *str2deque(string line) {
	deque<char*> *p = new deque<char*>();

	line.erase(0, 1);
	line.erase(line.length() - 1, 1);
	
	char *c = new char[line.length()];
	strcpy(c, line.c_str());

	char *token = strtok(c, ",");
	while (token != NULL) {
		p->push_back(token);
		token = strtok(NULL, ",");
	}

	return p;
}

void solution(string command, deque<char*> arr) {
	bool isReverse = false;

	for (int i = 0; i < command.length(); i++) {
		switch (command.at(i)) {
		case 'R':
			isReverse = !isReverse;
			break;
		case 'D':
			if (arr.size() == 0) {
				cout << "error";
				return;
			}
			if (isReverse) {
				arr.pop_back();
			}
			else {
				arr.pop_front();
			}
			break;
		}
	}

	cout << "[";
	while (arr.size() != 0) {
		if (!isReverse) {
			cout << arr.front();
			arr.pop_front();
		}
		else {
			cout << arr.back();
			arr.pop_back();
		}

		if (arr.size() != 0) {
			cout << ",";
		}
	}
	cout << "]";
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0);

	int count;
	cin >> count;

	for (int i = 0; i < count; i++) {
		string command;
		int size;
		string line;
		cin >> command >> size >> line;

		deque<char*> *arr = str2deque(line);

		solution(command, *arr);

		cout << "\n";

		delete(arr);
	}

	return 0;
}