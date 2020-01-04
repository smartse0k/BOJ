#include <iostream>

using namespace std;

int main(void) {
	cin.sync_with_stdio(false);
	cin.tie(0);

	int count;
	cin >> count;

	for(int i=0; i<count; i++) {
		int height, roomCount, number;
		cin >> height >> roomCount >> number;

		int floor = number % height;
		if(floor == 0) {
			floor = height;
		}

		double roomNumber = (double)number / (double)height;
		int iRoomNumber = (int)roomNumber;
		if(roomNumber > iRoomNumber) {
			iRoomNumber++;
		}

		cout << floor;
		if(iRoomNumber < 10) {
			cout << "0";
		}
		cout << iRoomNumber;
		cout << "\n";
	}

	return 0;
}