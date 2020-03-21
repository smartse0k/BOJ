#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int singerCount, inputCount;
vector<short> childList[1001];
short parentCount[1001];

queue<short> q;
vector<short> result;

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> singerCount >> inputCount;

	for (int i = 0; i < inputCount; i++) {
		int itemCount;
		cin >> itemCount;

		vector<short> singerList;

		for (int jj = 0; jj < itemCount; jj++) {
			short currentSinger;
			cin >> currentSinger;
			singerList.push_back(currentSinger);
		}

		for (int jj = 0; jj < itemCount; jj++) {
			if (jj != 0) {
				parentCount[singerList[jj]]++;
			}

			if (jj != itemCount - 1) {
				childList[singerList[jj]].push_back(singerList[jj + 1]);
			}
		}
	}
	
	for (int i = 1; i <= singerCount; i++) {
		if (parentCount[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		short popSinger = q.front();
		q.pop();
		result.push_back(popSinger);
		
		for (int i = 0; i < childList[popSinger].size(); i++) {
			short child = childList[popSinger][i];
			parentCount[child]--;

			if (parentCount[child] == 0) {
				q.push(child);
			}
		}
	}

	if (result.size() == singerCount) {
		for (int i = 0; i < singerCount; i++) {
			cout << result[i] << "\n";
		}
	} else {
		cout << 0;
	}

	return 0;
}
