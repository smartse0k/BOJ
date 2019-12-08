#include <iostream>
#include <math.h>

using namespace std;

int main(void) {
	int n1;
	char n2[10];
	int sum = 0;
	cin >> n1 >> n2;

	for(int i=2; i>=0; i--) {
		int n3 = n2[i] - '0';
		sum = sum + n1 * n3 * (pow(10.0, 2 - i));
		cout << n1 * n3 << "\n";
	}

	cout << sum;

	return 0;
}