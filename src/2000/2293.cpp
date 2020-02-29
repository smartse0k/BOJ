// 참고 풀이 과정 https://aerocode.net/105

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int coinCount; // 동전 종류 수
int target; // 목표 금액
int coinList[101]; // 동전 종류
int answerList[10001]; // x원을 만드는 경우의 수

int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);

	cin >> coinCount >> target;

	for (int i = 0; i < coinCount; i++) {
		cin >> coinList[i];
	}

	answerList[0] = 1; // 0원을 만드는 방법
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