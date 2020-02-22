#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main(void) {
	cin.tie(0);
	cin.sync_with_stdio(false);

	int cnt;
	cin >> cnt;

	int temp;
	vector<int> score;
	vector<pair<int, int>> acc;
	score.push_back(0);
	acc.push_back({0, 0});

	for (int i = 1; i <= cnt; i++) {
		cin >> temp;
		score.push_back(temp);
		
		if (i == 1) {
			acc.push_back({ score[i], score[i] });
		} else if(i == 2) {
			acc.push_back({ score[1] + score[2], score[2] });
		} else {
			// 한 칸씩 왔을 때
			int from1 = score[i] + acc[i - 1].second;
			
			// 두 칸씩 왔을 때
			int past1 = acc[i - 2].first;
			int past2 = acc[i - 2].second;
			int from2 = score[i] + (past1 > past2 ? past1 : past2);
			acc.push_back({from1, from2});
		}
	}

	cout << max(acc[cnt].first, acc[cnt].second);

	return 0;
}
