#include <iostream>
#include <vector>

using namespace std;

void pick(vector<pair<bool, int>> &v, vector<int> w, int depth, int maxDepth) {
	if (depth > maxDepth) {
		for (int jj = 0; jj < w.size(); jj++) {
			cout << w[jj] << " ";
		}
		cout << "\n";
		return;
	}
	
	for (int i = 0; i < v.size(); i++) {
		int maxNum = 0;
		if (w.size() > 0) {
			maxNum = w[w.size() - 1];
		}
		if (v[i].second >= maxNum) {
			if (depth <= maxDepth) {
				v[i].first = true;
				w.push_back(v[i].second);

				pick(v, w, depth + 1, maxDepth);

				w.pop_back();
				v[i].first = false;
			}
		}
	}
}

int main(void) {
	int N, M;
	cin >> N >> M;

	vector<pair<bool, int>> v; // 1~N, 사용여부
	vector<int> w; // pick한 애들이 들어가는거
	for (int i = 1; i <= N; i++) {
		v.push_back({false, i});
	}

	pick(v, w, 1, M);

	return 0;
}