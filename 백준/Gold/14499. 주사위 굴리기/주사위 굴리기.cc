#include <iostream>
#include <vector>
using namespace std;

int n, m, x, y, k;
int map[21][21];
int order[1001];
vector<int> dice(7);

int dx[5] = { 0, 1, -1, 0, 0 };
int dy[5] = { 0, 0 ,0, -1, 1 };

// 동 서 남 북 상 하 -> 1 2 3 4 5 6

// 동: 상 -> 동 / 동 -> 하 / 하 -> 서 / 서 -> 상 / 북 -> 북 / 남 -> 남
//	   5 -> 1 / 1 -> 6 / 6 -> 2 / 2 -> 5 / 4 / 3
// 서: 상 -> 서 / 서 -> 하 / 하 -> 동 / 동 -> 상 / 북 -> 북 / 남 -> 남
//     5 -> 2 / 2 -> 6 / 6 -> 1 / 1 -> 5 / 4 / 3
// 북: 상 -> 북 / 북 -> 하 / 하 -> 남 / 남 -> 상 / 동 -> 동 / 서 -> 서
//     5 -> 4 / 4 -> 6 / 6 -> 3 / 3 -> 5 / 1 / 2
// 남: 상 -> 남 / 남 -> 하 / 하 -> 북 / 북 -> 상 / 동 -> 동 / 서 -> 서
//     5 -> 3 / 3 -> 6 / 6 -> 4 / 4 -> 5 / 1 / 2

void input() {
	cin >> n >> m >> y >> x >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < k; i++) {
		cin >> order[i];
	}
}

void rollEast() {
	dice = { 0, dice[5], dice[6], dice[3], dice[4], dice[2], dice[1] };
}

void rollWest() {
	dice = { 0, dice[6], dice[5], dice[3], dice[4], dice[1], dice[2] };
}

void rollNorth() {
	dice = { 0, dice[1], dice[2], dice[6], dice[5], dice[3], dice[4] };
}

void rollSouth() {
	dice = { 0, dice[1], dice[2], dice[5], dice[6], dice[4], dice[3] };
}

void roll(int order) {
	switch (order) {
	case 1:
		rollEast();
		break;
	case 2:
		rollWest();
		break;
	case 3:
		rollNorth();
		break;
	case 4:
		rollSouth();
		break;
	default:
		break;
	}
}

void solve() {
	for (int i = 0; i < k; i++) {
		int ny = y + dy[order[i]];
		int nx = x + dx[order[i]];
		//cout << "ny = " << y << " / nx = " << x << " / map = " << map[y][x] << endl;
		if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
			y = ny;
			x = nx;
			roll(order[i]);

			if (map[y][x] == 0) {
				map[y][x] = dice[6];
			}
			else {
				dice[6] = map[y][x];
				map[y][x] = 0;
			}
			/*for (int j = 1; j < 7; j++) {
				cout << dice[j] << ' ';
			}
			cout << endl;*/
			cout << dice[5] << '\n';
		}
	}
}

int main() {
	input();
	solve();

	return 0;
}

// 주사위의 값을 기록하고 주사위를 굴렸을 때 어떻게 면이 바뀔지 생각해야함
// 움직이는 방향이 지도 내부인지 판단
// 주사위를 움직였을 때, 숫자를 바꾸는 것도 생각