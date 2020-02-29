// ���� Ǯ�� ���� https://aerocode.net/105

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int coinCount; // ���� ���� ��
int target; // ��ǥ �ݾ�
int coinList[101]; // ���� ����
int answerList[10001]; // x���� ����� ����� ��

int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);

	cin >> coinCount >> target;

	for (int i = 0; i < coinCount; i++) {
		cin >> coinList[i];
	}

	answerList[0] = 1; // 0���� ����� ���
	for (int i = 0; i < coinCount; i++) {
		int currentCoinPrice = coinList[i];
		for (int price = 1; price <= target; price++) {
			if (price - currentCoinPrice >= 0) {
				answerList[price] += answerList[price - currentCoinPrice];
			}
		}
	}

	cout << answerList[target];

	return 0;
}