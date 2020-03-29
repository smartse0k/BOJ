#include <iostream>
#include <vector>
#include <set>
#include <queue>

#define INF 20000 * 10 + 1
#define PATHINFO pair<int, int>

using namespace std;

struct cmp {
	bool operator()(PATHINFO p1, PATHINFO p2) {
		return p1.first > p2.first;
	}
};

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int vCount, eCount, startVertex;
	cin >> vCount >> eCount >> startVertex;

	set<int> *vList = new set<int>[vCount + 1];
	vector< PATHINFO > *path = new vector< PATHINFO >[vCount + 1];

	for (int i = 0; i < eCount; i++) {
		int start, end, weight;
		cin >> start >> end >> weight;

		vList[start].insert(end);
		path[start].push_back({ weight, end });
	}

	int *resultPath = new int[vCount + 1];
	for (int i = 0; i <= vCount; i++) {
		resultPath[i] = INF;
	}

	priority_queue< PATHINFO, vector<PATHINFO>, cmp > q;
	q.push({ 0, startVertex });
	resultPath[startVertex] = 0;

	while (!q.empty()) {
		PATHINFO currentPath = q.top();
		q.pop();

		int currentWeight = currentPath.first;
		int currentVertex = currentPath.second;

		if (resultPath[currentVertex] != currentWeight) {
			continue;
		}

		for (int i = 0; i < path[currentVertex].size(); i++) {
			int nextWeight = path[currentVertex][i].first;
			int nextVertex = path[currentVertex][i].second;
			int sum = currentWeight + nextWeight;
			if (resultPath[nextVertex] > sum) {
				resultPath[nextVertex] = sum;
				q.push({ sum, nextVertex });
			}
		}
	}

	for (int i = 1; i <= vCount; i++) {
		if (resultPath[i] == INF) {
			cout << "INF\n";
		} else {
			cout << resultPath[i] << "\n";
		}
	}


	delete[] vList;
	delete[] path;
	delete[] resultPath;

	return 0;
}
