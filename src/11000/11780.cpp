#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const int maxCost = 100000 * 100 + 1;
int N;
int cnt;
int **map;
int **path;

void printMap() {
	for (int i = 1; i < N + 1; i++) {
		for (int jj = 1; jj < N + 1; jj++) {
			if (map[i][jj] == maxCost) {
				cout << 0 << " ";
			}
			else {
				cout << map[i][jj] << " ";
			}

		}
		cout << "\n";
	}
}

void printPath() {
	for (int start = 1; start <= N; start++) {
		for (int end = 1; end <= N; end++) {
			if (start == end) {
				cout << "0\n";
				continue;
			}

			vector<int> pathList;
			pathList.push_back(start);

			if (start == 1 && end == 5) {
				cout << "";
			}

			int next = path[start][end];
			while (next != end) {
				pathList.push_back(next);
				next = path[next][end];
			}

			pathList.push_back(next);

			if (map[start][end] != maxCost) {
				cout << pathList.size() << " ";
				for (int i = 0; i < pathList.size(); i++) {
					cout << pathList[i] << " ";
				}
				cout << "\n";
			} else {
				cout << "0\n";
			}
		}
	}
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> cnt;

	map = new int *[N + 1];
	path = new int *[N + 1];
	for (int i = 0; i < N + 1; i++) {
		map[i] = new int[N + 1];
		path[i] = new int[N + 1];

		for (int jj = 0; jj < N + 1; jj++) {
			map[i][jj] = (i == jj) ? 0 : maxCost;
			path[i][jj] = -1;
		}
	}

	for (int jj = 0; jj < cnt; jj++) {
		int start, end, cost;
		cin >> start >> end >> cost;

		if (map[start][end] > cost) {
			map[start][end] = cost;
			path[start][end] = end;
		}
	}

	for (int i = 1; i <= N; i++) { // 거쳐갈거
		for (int jj = 1; jj <= N; jj++) { // 시작
			for (int kkk = 1; kkk <= N; kkk++) { // 끝
				int currentCost = map[jj][kkk];
				int newCost = map[jj][i] + map[i][kkk];
				if (currentCost > newCost) {
					if (jj == 2 && kkk == 1) {
						cout << "";
					}

					path[jj][kkk] = path[jj][i];
					map[jj][kkk] = map[jj][i] + map[i][kkk];
				}
			}
		}
	}

	printMap();
	printPath();

	return 0;
}
