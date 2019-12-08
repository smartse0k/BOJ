#include <iostream>

using namespace std;

int main(void) {
	while(true) {
		int n1, n2;
		cin >> n1 >> n2;

		if(cin.eof()) {
			break;
		}

		cout << n1 + n2 << "\n";
	}

	return 0;
}