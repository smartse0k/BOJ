#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int testCount;

void inputAndSolve() {
	int buildingCount, techCount;
	cin >> buildingCount >> techCount;

	vector<int> buildTimeList; // 걸리는 시간
	vector<int> buildAccTimeList; // 누적된 시간
	buildTimeList.push_back(0); // 0번째 건물 시간
	buildAccTimeList.push_back(0); // 0번째 건물 시간
	for (int i = 0; i < buildingCount; i++) {
		int inputTime = 0;
		cin >> inputTime;
		buildTimeList.push_back(inputTime);
		buildAccTimeList.push_back(inputTime);
	}

	vector<int> *childList = new vector<int>[buildingCount + 1];
	int *parentCount = new int[buildingCount + 1];

	for (int i = 0; i <= buildingCount; i++) {
		parentCount[i] = 0;
	}

	for (int i = 0; i < techCount; i++) {
		int parent, child;
		cin >> parent >> child;

		childList[parent].push_back(child);
		parentCount[child]++;
	}

	queue<int> q;
	for (int i = 1; i <= buildingCount; i++) {
		if (parentCount[i] == 0) {
			q.push(i);
		}
	}


	int resultIndex;
	cin >> resultIndex;

	while (!q.empty()) {
		int buildingIndex = q.front();
		q.pop();

		if (buildingIndex == resultIndex) {
			break;
		}

		for (int i = 0; i < childList[buildingIndex].size(); i++) {
			int child = childList[buildingIndex][i];
			parentCount[child]--;

			// 자식이 걸리는 시간 계산
			int dueTime = buildAccTimeList[buildingIndex] + buildTimeList[child];
			if (buildAccTimeList[child] < dueTime) {
				// 더 오래 걸리는 시간이면 업데이트
				buildAccTimeList[child] = dueTime;
			}

			if (parentCount[child] == 0) {
				q.push(child);
			}
		}
	}

	cout << buildAccTimeList[resultIndex] << "\n";

	delete[] childList;
	delete[] parentCount;
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> testCount;
	for (int i = 0; i < testCount; i++) {
		inputAndSolve();
	}

	return 0;
}
