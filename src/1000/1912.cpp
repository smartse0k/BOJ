#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int cnt;
int a[100001];
int s[100001];

int main(void) {
	cin.tie(0);
	cin.sync_with_stdio(false);

	cin >> cnt;

	for (int i = 0; i < cnt; i++) {
		cin >> a[i];
	}
	
	s[0] = a[0];

	for (int i = 1; i < cnt; i++) {
		s[i] = s[i - 1] + a[i];

		if (s[i] < a[i]) {
			s[i] = a[i];
		}
	}

	int result = 0x80000000L;
	for (int i = 0; i < cnt; i++) {
		result = max(result, s[i]);
	}

	return 0;
}
	