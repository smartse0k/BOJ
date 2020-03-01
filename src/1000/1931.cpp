#include <iostream>
#include <algorithm>

using namespace std;

int councilCount;
pair<int, int> councilTime[100001];

bool sorting(const pair<int, int> &a, const pair<int, int> &b) {
	if (a.second == b.second) {
		return a.first < b.first;
	} else {
		return a.second < b.second;
	}
}

int main(void) {
	cin.tie(0);
	cin.sync_with_stdio(false);

	cin >> councilCount;
	for (int i = 0; i < councilCount; i++) {
		cin >> councilTime[i].first >> councilTime[i].second;
	}
	sort(councilTime, councilTime + councilCount, sorting);
	
	int result = 0;
	pair<int, int> *currentCouncil = nullptr;
	for (int i = 0; i < councilCount; i++) {
		if (currentCouncil == nullptr ||
				(
					currentCouncil->second <= councilTime[i].first
					&&
					currentCouncil->second <= councilTime[i].second
				)
		   )
		{
			currentCouncil = &councilTime[i];
			//cout << "다음 회의: " << currentCouncil->first << " ~ " << currentCouncil->second << endl;
			result++;
		}
	}

	cout << result;

	return 0;
}