#include <iostream>

using namespace std;

const int maxCost = 100000 * 100 + 1;
int N;
int cnt;
int **map;

void printMap() {
	for (int i = 1; i < N + 1; i++) {
		for (int jj = 1; jj < N + 1; jj++) {
			if (map[i][jj] == maxCost) {
				cout << 0 << " ";
			} else {
				cout << map[i][jj] << " ";
			}
			
		}
		cout << "\n";
	}
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> cnt;

	map = new int *[N + 1];
	for (int i = 0; i < N + 1; i++) {
		map[i] = new int[N + 1];

		for (int jj = 0; jj < N + 1; jj++) {
			map[i][jj] = (i == jj) ? 0 : maxCost;
		}
	}

	for (int jj = 0; jj < cnt; jj++) {
		int start, end, cost;
		cin >> start >> end >> cost;

		if (map[start][end] > cost) {
			map[start][end] = cost;
		}
	}

	//for (int a = 0; a < N; a++) {
		for (int i = 1; i <= N; i++) { // 거쳐갈거
			for (int jj = 1; jj <= N; jj++) { // 시작
				for (int kkk = 1; kkk <= N; kkk++) { // 끝
					int currentCost = map[jj][kkk];
					int newCost = map[jj][i] + map[i][kkk];
					if (currentCost > newCost) {
						map[jj][kkk] = map[jj][i] + map[i][kkk];
					}
				}
			}
		}
	//}
	
	printMap();

	return 0;
}
