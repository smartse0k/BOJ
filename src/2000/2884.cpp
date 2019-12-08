#include <iostream>

using namespace std;

int main(void) {
	int hour, minute;
	cin >> hour >> minute;

	if(minute < 45) {
		hour--;
		minute = 45 - minute;
		minute = 60 - minute;

		if(hour == -1) {
			hour = 23;
		}
	} else {
		minute -= 45;
	}

	cout << hour << " " << minute;

	return 0;
}