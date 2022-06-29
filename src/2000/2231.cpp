#include <iostream>

using namespace std;

int sum(int input) {
	int sum = input;

	while(input != 0) {
		int current = input % 10;
		sum += current;
		input /= 10;
	}

	return sum;
}

int main(void) {
	cin.sync_with_stdio(false);
	cin.tie(0);

	int input;
	cin >> input;

	int find = input;
	for(int i=input; i>0; i--) {
		int s = sum(i);
		if(s == input) {
			find = i;
		}
	}

	if(find == input) {
		cout << 0;
	} else {
		cout << find;
	}

	return 0;
}