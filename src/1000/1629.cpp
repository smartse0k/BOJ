#include <iostream>

using namespace std;

int main(void) {
	cin.sync_with_stdio(false);
	cin.tie(0);

	int A = 0, B = 0, C = 0;
	cin >> A >> B >> C;
	
	int s = 1;
	int *cache = new int[C];
	int cacheIndex = 0;
	int cacheIndex2 = 0;
	for(int i=0; i<B; i++) {
		if(cacheIndex < C) {
			s *= A;
			s = s % C;
			cache[cacheIndex++] = s;
		} else {
			cacheIndex2++;
			if(cacheIndex >= C) {
				cacheIndex2 = 0;
			}
			s = cache[cacheIndex2];
		}
	}
		
	cout << s;

	return 0;
}