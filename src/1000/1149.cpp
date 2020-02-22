#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

enum {
	R = 0,
	G,
	B,
};

class Price {
public:
	int price[3];

	Price() {
		for (int i = 0; i < 3; i++)
			price[i] = 0x7FFFFFFF;
	}

	inline void input() {
		for (int i = 0; i < 3; i++)
			cin >> price[i];
	}
};

int main(void) {
	cin.tie(0);
	cin.sync_with_stdio(false);

	int cnt;
	cin >> cnt;

	vector<Price*> priceList;
	vector<Price*> totalPriceList;

	for (int i = 0; i < cnt; i++) {
		Price *price = new Price();
		price->input();
		priceList.push_back(price);

		if (i == 0) {
			totalPriceList.push_back(price);
			continue;
		}

		Price *currentTotalPrice = new Price();
		totalPriceList.push_back(currentTotalPrice);
		for (int thisColorIdx = 0; thisColorIdx < 3; thisColorIdx++) {
			for (int backColorIdx = 0; backColorIdx < 3; backColorIdx++) {
				if (thisColorIdx == backColorIdx) {
					continue;
				}

				int currentPrice = price->price[thisColorIdx] + totalPriceList[i - 1]->price[backColorIdx];

				currentTotalPrice->price[thisColorIdx] = min(currentTotalPrice->price[thisColorIdx], currentPrice);
			}
		}
	}

	Price *last = totalPriceList[cnt - 1];
	cout << min(min(last->price[0], last->price[1]), last->price[2]);

	return 0;
}