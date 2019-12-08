#include <iostream>
#include <queue>

#define POSITION std::pair<int, int>
#define POSITION_QUEUE std::queue<POSITION *>

POSITION_QUEUE *pQueue = new POSITION_QUEUE();
POSITION *posOne = NULL;
char map[501][501];
bool visit[501][501];

int width, height, size;

POSITION *findOne() {
	for(int y=0; y<height; y++) {
		for(int x=0; x<width; x++) {
			if(map[x][y] == '1') {
				return new POSITION(x, y);
			}
		}
	}
	return NULL;
}

void processBFS() {
	POSITION *position = pQueue->front();
	pQueue->pop();

	int x = position->first;
	int y = position->second;

	//delete position;

	map[x][y] = '2';

#define CHECKONE(x, y) map[x][y] == '1'
#define VISIT(x, y) visit[x][y] == false

	if(x > 0) {
		if(CHECKONE(x - 1, y) && VISIT(x - 1, y)) {
			visit[x - 1][y] = true;
			pQueue->push(new POSITION(x - 1, y));
		}
	}
	if(x < width) {
		if(CHECKONE(x + 1, y) && VISIT(x + 1, y)) {
			visit[x + 1][y] = true;
			pQueue->push(new POSITION(x + 1, y));
		}
	}
	if(y > 0) {
		if(CHECKONE(x, y - 1) && VISIT(x, y - 1)) {
			visit[x][y - 1] = true;
			pQueue->push(new POSITION(x, y - 1));
		}
	}
	if(y < height) {
		if(CHECKONE(x, y + 1) && VISIT(x, y + 1)) {
			visit[x][y + 1] = true;
			pQueue->push(new POSITION(x, y + 1));
		}
	}
}

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int resImageCount = 0;
	int resMaxImageSize = 0;

	// ���� �Է�
	std::cin >> height >> width;
	size = width * height;

	// �� ����
	//map = new char*[height];
	for(int y=0; y<height; y++) {
		//map[y] = new char[width];

		for(int x=0; x<width; x++) {
			std::cin >> map[y][x];
		}
	}
	
	// BFS ť
	while((posOne = findOne()) != NULL) {
		resImageCount++;

		int currentImageSize = 0;

		pQueue->push(posOne);

		while(!pQueue->empty()) {
			currentImageSize++;
			processBFS();
		}

		if(currentImageSize > resMaxImageSize) {
			resMaxImageSize = currentImageSize;
		}
	}

	// �޸� ����
	//for(int y=0; y<height; y++) {
	//	delete map[y];
	//}
	//delete map;

	// ���
	std::cout << resImageCount << '\n' << resMaxImageSize;

	return 0;
}