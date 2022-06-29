#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	cin.sync_with_stdio(false);
	cin.tie(0);

	int cnt;
	cin >> cnt;

	pair<int, int> p[100];

	for(int i=0; i<cnt; i++) {
		int w, h;
		cin >> w >> h;

		p[i] = pair<int, int>(w, h);
	}

	for(int i=0; i<cnt; i++) {
		int rank = 1;

		for(int jj=0; jj<cnt; jj++) {
			if(i == jj) {
				continue;
			}

			if(p[i].first < p[jj].first && p[i].second < p[jj].second) {
				rank++;
			}
		}

		cout << rank << " ";
	}

	return 0;
}