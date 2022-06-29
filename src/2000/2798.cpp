#include <iostream>
#include <vector>

using namespace std;

int find(vector<int> &v, int &M) {
	int temp = 0;
	int result = 0;

	for(int i=0; i<v.size(); i++) {
		temp = v[i];

		if(temp > M) {
			continue;
		}

		for(int jj=i+1; jj<v.size(); jj++) {
			temp += v[jj];

			if(temp > M) {
				temp -= v[jj];
				continue;
			}

			for(int kkk=jj+1; kkk<v.size(); kkk++) {
				temp += v[kkk];

				if(temp > M) {
					temp -= v[kkk];
					continue;
				}

				if(temp == M) {
					return M;
				}

				if(temp > result) {
					result = temp;
				}

				temp -= v[kkk];
			}

			temp -= v[jj];
		}
	}

	return result;
}

int main(void) {
	cin.sync_with_stdio(false);
	cin.tie(0);

	int count, M;
	cin >> count >> M;

	vector<int> v;

	for(int i=0; i<count; i++) {
		int input;
		cin >> input;
		v.push_back(input);
	}

	int result = find(v, M);
	cout << result;

	return 0;
}