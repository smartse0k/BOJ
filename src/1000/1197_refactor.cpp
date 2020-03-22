#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;

int vCount, rowCount;

//                start end weight
#define EDGE tuple<int, int, int>
#define _get(t, index) std::get<index>(t)
vector< EDGE > v[10001];

struct cmp {
	bool operator() (EDGE i1, EDGE i2) {
		return std::get<2>(i1) > std::get<2>(i2);
	}
};
//            vertex
priority_queue<EDGE, vector<EDGE>, cmp> q;

bool isVisit[10001];

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> vCount >> rowCount;

	for (int i = 0; i < rowCount; i++) {
		int start, end, weight;
		cin >> start >> end >> weight;
		v[start].push_back(make_tuple(start, end, weight));
		v[end].push_back(make_tuple(end, start, weight));
	}

	for (int i = 0; i < v[1].size(); i++) {
		EDGE currentEdge = v[1][i];
		if (_get(currentEdge, 0) == 1) {
			q.push(currentEdge);
		}
	}

	int result = 0;
	int count = 0;
	while (true) {
		EDGE current = q.top();
		q.pop();

		int start, end, weight;
		std::tie(start, end, weight) = current;

		if (isVisit[start] && isVisit[end]) {
			continue;
		}

		isVisit[start] = true;
		isVisit[end] = true;
		result += weight;
		count++;

		if (count == vCount - 1) {
			break;
		}

		for (int i = 0; i < v[end].size(); i++) {
			//if (_get(v[end][i], 0) == end) {
				q.push(v[end][i]);
			//}
		}
	}

	cout << result;

	return 0;
}
