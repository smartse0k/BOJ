#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> *grape;
vector<bool> isVisitDFS(1001, false);
vector<bool> isVisitBFS(1001, false);

void dfs(int startAt) {
	cout << startAt << " ";

	for(int i=0; i<grape[startAt].size(); i++) {
		int next = grape[startAt][i];
		if(!isVisitDFS[next]) {
			isVisitDFS[next] = true;
			dfs(next);
		}
	}
}

void bfs(int startAt) {
	queue<int> q;
	q.push(startAt);
	while(q.size() > 0) {
		int current = q.front();
		q.pop();
		cout << current << " ";

		for(int i=0; i<grape[current].size(); i++) {
			int next = grape[current][i];
			if(!isVisitBFS[next]) {
				isVisitBFS[next] = true;
				q.push(next);
			}
		}
	}
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int vCount, edgeCount, startAt;
	cin >> vCount >> edgeCount >> startAt;

	grape = new vector<int>[vCount + 1];
	for(int i=0; i<edgeCount; i++) {
		int start, end;
		cin >> start >> end;
		grape[start].push_back(end);
		grape[end].push_back(start);
	}

	for(int i=1; i<=vCount; i++) {
		sort(grape[i].begin(), grape[i].begin() + grape[i].size());
	}
	
	isVisitDFS[startAt] = true;
	dfs(startAt);
	
	cout << "\n";

	isVisitBFS[startAt] = true;
	bfs(startAt);

	return 0;
}
