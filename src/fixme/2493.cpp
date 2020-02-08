#include <iostream>
#include <queue>

#define POSITION std::pair<int, int>
#define POSITION_QUEUE std::queue<POSITION *>

using namespace std;

pair<int, int> *findOne(char **map, int width, int height) {
	for (int y = 0; y<height; y++) {
		for (int x = 0; x<width; x++) {
			if (map[x][y] == '1') {
				return new pair<int, int>(x, y);
			}
		}
	}
	return NULL;
}

void processBFS(char **map, int width, int height, queue<pair<int, int> *> *pQueue) {
	pair<int, int> *position = pQueue->front();
	pQueue->pop();

	int x = position->first;
	int y = position->second;

	delete position;

	map[x][y] = '2';

#define CHECKONE(x, y) map[x][y] == '1'

	if (x > 0) {
		if (CHECKONE(x - 1, y)) {
			pQueue->push(new pair<int, int>(x - 1, y));
		}
	}
	if (x < width - 1) {
		if (CHECKONE(x + 1, y)) {
			pQueue->push(new pair<int, int>(x + 1, y));
		}
	}
	if (y > 0) {
		if (CHECKONE(x, y - 1)) {
			pQueue->push(new pair<int, int>(x, y - 1));
		}
	}
	if (y < height - 1) {
		if (CHECKONE(x, y + 1)) {
			pQueue->push(new pair<int, int>(x, y + 1));
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int resImageCount = 0;
	int resMaxImageSize = 0;

	// 지도 입력
	int width, height, size;
	cin >> height >> width;
	size = width * height;

	// 맵 생성
	char **map = new char*[height];
	for (int y = 0; y<height; y++) 
	{
		map[y] = new char[width];
		for (int x = 0; x<width; x++) 
		{
			cin >> map[y][x];
		}
	}

	// BFS 큐
	queue<pair<int, int> *> *pQueue = new queue<pair<int, int> *>();

	pair<int, int> *posOne = NULL;
	//while ((posOne = findOne(map, width, height)) != NULL) {

	for (int y = 0; y < height; y++) 
	{
		for (int x = 0; x < width; x++) 
		{
			if (map[x][y] == '1')
			{
				posOne = new pair<int, int>(x, y);
				resImageCount++;

				int currentImageSize = 0;

				pQueue->push(posOne);

				while (!pQueue->empty()) {
					currentImageSize++;
					processBFS(map, width, height, pQueue);
				}

				if (currentImageSize > resMaxImageSize) {
					resMaxImageSize = currentImageSize;
				}
			}
		}
	}
		
	//}

	// 메모리 해제
	for (int y = 0; y<height; y++) {
		delete map[y];
	}
	delete map;

	// 결과
	cout << resImageCount << '\n' << resMaxImageSize;

	return 0;
}