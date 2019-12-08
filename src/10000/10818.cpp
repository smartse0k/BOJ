#include <iostream>
#include <climits>

using namespace std;

int main(void) {
	int max = INT_MIN;
	int min = INT_MAX;

	int count;
	cin >> count;

	for(int i=0; i<count; i++) {
		int n;
		cin >> n;

		if(n < min) {
			min = n;
		}

		if(n > max) {
			max = n;
		}
	}

	cout << min << " " << max;

	return 0;
}