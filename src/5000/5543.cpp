#include <iostream>

using namespace std;

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n[5];
	cin >> n[0] >> n[1] >> n[2] >> n[3] >> n[4];
	
	int burger = n[0], drink = n[3];
	if (burger > n[1]) {
		burger = n[1];
	}
	if (burger > n[2]) {
		burger = n[2];
	}
	if (drink > n[4]) {
		drink = n[4];
	}

	cout << (burger + drink - 50);

	return 0;
}
