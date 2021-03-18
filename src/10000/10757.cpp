#include <iostream>
#include <string>
#include <utility>
#include <stack>

using namespace std;

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	string a, b;
	cin >> a >> b;

	string s = "";

	int LA = a.length(),
		LB = b.length();
	int maxLength = max(LA, LB);

	int carry = 0;
	stack<int> sum;
	for (int i = 0; i < maxLength; i++) {
		int x = 0, y = 0;

		if (i < LA) {
			x = a[LA - i - 1] - '0';
		}

		if (i < LB) {
			y = b[LB - i - 1] - '0';
		}

		int s = x + y + carry;
		if (s >= 10) {
			carry = s / 10;
			s = s % 10;
		} else {
			carry = 0;
		}

		sum.push(s);
	}

	if (carry > 0) {
		cout << carry;
	}

	while (!sum.empty()) {
		cout << sum.top();
		sum.pop();
	}

	return 0;
}
