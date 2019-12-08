#include <iostream>
#include <climits>

using namespace std;

int main(void) {
	bool mod[42];

	for(int i=0; i<42; i++) {
		mod[i] = false;
	}

	for(int i=0; i<10; i++) {
		int n;
		cin >> n;

		mod[n % 42] = true;
	}

	int result = 0;
	for(int i=0; i<42; i++) {
		if(mod[i]) {
			result++;
		}
	}

	cout << result;

	return 0;
}