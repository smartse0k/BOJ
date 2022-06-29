#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int vCount, edgeCount;
	cin >> vCount >> edgeCount;

	vector<int> *grape = new vector<int>[vCount + 1];
	bool *isVisit = new bool[vCount + 1];
	for(int i=1; i<=edgeCount; i++) {
		int start, end;
		cin >> start >> end;
		grape[start].push_back(end);
		grape[end].push_back(start);

		isVisit[start] = false;
	}

	queue<int> bfs;
	int result = 0;
	while(true) {
		// 시작점 찾기
		int start = -1;
		for(int i=1; i<=vCount; i++) {
			if(!isVisit[i]) {
				start = i;
				break;
			}
		}
		
		// 탐색하지 않은 곳이 없다
		if(start == -1) {
			break;
		}

		result++;

		bfs.push(start);
		isVisit[start] = true;

		while(bfs.size() > 0) {
			int current = bfs.front();
			bfs.pop();

			for(int i=0; i<grape[current].size(); i++) {
				int next = grape[current][i];
				
				if(isVisit[next]) {
					continue;
				}

				isVisit[next] = true;
				bfs.push(next);
			}
		}
	}

	cout << result;
	return 0;
}
