#include <iostream>

using namespace std;

long long factorial(int n) {
	if(n <= 1) {
		return 1;
	} else {
		return n * factorial(n - 1);
	}
}

int main(void) {
	cin.sync_with_stdio(false);
	cin.tie(0);

	int input = 0;
	cin >> input;

	cout << factorial(input);

	return 0;
}