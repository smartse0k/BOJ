#include <iostream>
#include <vector>
#include <queue>


using namespace std;

int N, M;
vector<short> childList[33000];
int indegreeCount[33000];

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		short h1, h2;
		cin >> h1 >> h2;

		childList[h1].push_back(h2);
		indegreeCount[h2]++;
	}

	int leftN = N;
	while (leftN > 0) {
		for (int i = 1; i <= N; i++) {
			if (indegreeCount[i] == 0) {
				leftN--;
				indegreeCount[i]--;

				for (int jj = 0; jj < childList[i].size(); jj++) {
					short ind = childList[i][jj];
					indegreeCount[ind]--;
				}

				cout << i << " ";
			}
		}
	}

	return 0;
}
