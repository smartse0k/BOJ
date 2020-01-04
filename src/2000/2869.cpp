#include <iostream>

using namespace std;

int main(void) {
	double up, down, height;
	cin >> up >> down >> height;

	double days = (height - up) / (up - down) + 1.0;
	int iDays = (int)days;
	if(days > iDays) {
		iDays++;
	}

	cout << iDays;

	return 0;
}