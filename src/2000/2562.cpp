#include <iostream>
#include <climits>

using namespace std;

int main(void) {
	int max = INT_MIN;
	int maxpos = 0;

	for(int i=0; i<9; i++) {
		int num;
		cin >> num;
		if(num > max) {
			max = num;
			maxpos = i + 1;
		}
	}

	cout << max << "\n" << maxpos;

	return 0;
}