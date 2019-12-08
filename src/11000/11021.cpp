#include <iostream>

using namespace std;

int main(void) {
	int count;
	cin >> count;

	for(int i=0; i<count; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		cout << "Case #" << i + 1 << ": " << n1 + n2 << "\n";
	}

	return 0;
}