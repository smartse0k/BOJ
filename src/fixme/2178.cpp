#include <iostream>
#include <queue>

using namespace std;

bool map[101][101];
bool visit[101][101];

#define POSITION pair<int, int>
queue<POSITION> q;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);

	int width, height;
	cin >> height >> width;

	char input[101];
	for (int y = 0; y < height; y++) {
		cin >> input;
		for (int x = 0; x < width; x++) {
			map[y][x] = input[x] == '1';
		}
	}

	q.push(POSITION(0, 0));

	while (!q.empty()) {
		POSITION current = q.front();
		q.pop();

		int cx = current.first;
		int cy = current.second;

		visit[cy][cx] = true;

		// 결과 발견
		if (cx == width - 1 && cy == height - 1) {
			break;
		}

		// 인접 맵
		if (cx > 0 && map[cy][cx - 1] == 1 && !visit[cy][cx - 1]) {
			q.push(POSITION(cx - 1, cy));
			map[cy][cx - 1] = map[cy][cx] + 1;
		}
		if (cx < width && map[cy][cx + 1] == 1 && !visit[cy][cx + 1]) {
			q.push(POSITION(cx + 1, cy));
			map[cy][cx + 1] = map[cy][cx] + 1;
		}
		if (cy > 0 && map[cy - 1][cx] == 1 && !visit[cy - 1][cx]) {
			q.push(POSITION(cx, cy - 1));
			map[cy - 1][cx] = map[cy][cx] + 1;
		}
		if (cy < height && map[cy + 1][cx] == 1 && !visit[cy + 1][cx]) {
			q.push(POSITION(cx, cy + 1));
			map[cy + 1][cx] = map[cy][cx] + 1;
		}
	}

	cout << map[height - 1][width - 1];
	
	return 0;
}