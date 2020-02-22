#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int cnt;
int a[1002];
int ret[1002];

int main(void) {
	cin.tie(0);
	cin.sync_with_stdio(false);

	cin >> cnt;

	for (int i = 0; i < cnt; i++) {
		cin >> a[i];
	}

	ret[0] = 1;
	for (int i = 1; i < cnt; i++) {
		int index = -1;
		for (int jj = i - 1; jj >= 0; jj--) {
			if (a[i] > a[jj]) {
				if (ret[index] < ret[jj]) {
					index = jj;
				}
			}
		}
		ret[i] = (index == -1 ? 0 : ret[index]) + 1;
	}

	cout << *max_element(ret, ret + cnt);

	return 0;
}