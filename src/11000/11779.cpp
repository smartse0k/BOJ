#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <stack>

#define INF 100000 * 1000 + 1
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

	int vCount, eCount;
	cin >> vCount >> eCount;

	set<int> *vList = new set<int>[vCount + 1];
	vector< PATHINFO > *path = new vector< PATHINFO >[vCount + 1];

	for (int i = 0; i < eCount; i++) {
		int start, end, weight;
		cin >> start >> end >> weight;

		vList[start].insert(end);
		path[start].push_back({ weight, end });
	}

	int startVertex, endVertex;
	cin >> startVertex >> endVertex;

	int *resultCost = new int[vCount + 1];
	int *resultPath = new int[vCount + 1];
	for (int i = 0; i <= vCount; i++) {
		resultCost[i] = INF;
		resultPath[i] = INF;
	}

	priority_queue< PATHINFO, vector<PATHINFO>, cmp > q;
	q.push({ 0, startVertex });
	resultCost[startVertex] = 0;
	resultPath[startVertex] = 0;

	while (!q.empty()) {
		PATHINFO currentPath = q.top();
		q.pop();

		int currentWeight = currentPath.first;
		int currentVertex = currentPath.second;

		if (resultCost[currentVertex] != currentWeight) {
			continue;
		}

		for (int i = 0; i < path[currentVertex].size(); i++) {
			int nextWeight = path[currentVertex][i].first;
			int nextVertex = path[currentVertex][i].second;
			int sum = currentWeight + nextWeight;
			if (resultCost[nextVertex] > sum) {
				resultCost[nextVertex] = sum;
				resultPath[nextVertex] = currentVertex;
				q.push({ sum, nextVertex });
			}
		}
	}

	cout << resultCost[endVertex] << "\n";

	stack<int> resultPathStack;
	int next = endVertex;
	resultPathStack.push(next);
	while (true) {
		resultPathStack.push(resultPath[next]);
		if (resultPath[next] == startVertex) {
			break;
		}
		next = resultPath[next];
	}

	cout << resultPathStack.size() << "\n";
	while (!resultPathStack.empty()) {
		cout << resultPathStack.top() << " ";
		resultPathStack.pop();
	}

	delete[] vList;
	delete[] path;
	delete[] resultCost;
	delete[] resultPath;

	return 0;
}
