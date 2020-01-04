#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
	cin.sync_with_stdio(false);
	cin.tie(0);

	int count;
	cin >> count;

	for(int i=0; i<count; i++) {
		int x, y, r, x2, y2, r2;

		cin >> x >> y >> r;
		cin >> x2 >> y2 >> r2;

		// ���� ���
		if(x == x2 && y == y2) {
			if(r == r2) {
				cout << -1;
			} else {
				cout << 0;
			}
			cout << "\n";
			continue;
		}

		// �߽ɰ��� �Ÿ�
		int distance = 0;
		double xx = x2 - x;
		double yy = y2 - y;
		xx *= xx;
		yy *= yy;
		distance = (int)sqrt(xx + yy);

		if(r >= distance || r2 >= distance) { // c1�� c2�� �����ϴ� ���
			if(distance + r2 > r || distance + r > r2) {
				cout << 2 << "\n";
				continue;
			} else if(distance == (r - r2) || distance == (r2 - r)) {
				cout << 1 << "\n";
				continue;
			} else {
				cout << 0 << "\n";
				continue;
			}
		} else { // �������� �ʴ� ���
			if(distance > (r + r2)) {
				cout << 0 << "\n";
				continue;
			} else if(distance == (r + r2)) {
				cout << 1 << "\n";
				continue;
			} else {
				cout << 2 << "\n";
				continue;
			}
		}
	}

	return 0;
}