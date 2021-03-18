#include <iostream>
#include <string>

using namespace std;

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	int num = 666;
	int M = 0;

	while (true) {
		string test = to_string(num);
		if (test.find("666") != -1) {
			M++;
		}

		if (N == M) {
			break;
		}

		num++;
	}

	cout << num;

	return 0;
}
