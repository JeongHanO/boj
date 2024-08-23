#include <iostream>
using namespace std;


// 0: 상(w) / 1: 하(y) / 2: 앞(r) / 3: 뒤(o) / 4: 좌(g) / 5: 우(b)
char color[6] = { 'w', 'y', 'r', 'o', 'g', 'b' };
char cube[6][3][3]; // 3*3 6개.
int T;

void init() {
	for (int i = 0; i < 6; i++) {
		for (int x = 0; x < 3; x++) {
			for (int y = 0; y < 3; y++) {
				cube[i][x][y] = color[i];
			}
		}
	}
}

void rotate_face(int face, char clock) {
	// 해당 면(c)을 회전
	char tmp[3][3]; // 임시 배열
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			tmp[i][j] = cube[face][i][j];
		}
	}
	// clock에 따라서 회전 방향 결정
	if (clock == '+') { // 시계 방향
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cube[face][j][2 - i] = tmp[i][j];
			}
		}
	}
	else { // 반시계 방향
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cube[face][2 - j][i] = tmp[i][j];
			}
		}
	}
}

void rotate_side_U(char clock) { // 윗면 회전
	int tmp[3];
	for (int i = 0; i < 3; i++) tmp[i] = cube[3][2][i];

	if (clock == '+') { // 시계 방향
		// 좌4 -> 뒤3
		cube[3][2][0] = cube[4][2][2];
		cube[3][2][1] = cube[4][1][2];
		cube[3][2][2] = cube[4][0][2];
		// 앞2 -> 좌4
		cube[4][0][2] = cube[2][0][0];
		cube[4][1][2] = cube[2][0][1];
		cube[4][2][2] = cube[2][0][2];
		// 우5->앞2
		cube[2][0][0] = cube[5][2][0];
		cube[2][0][1] = cube[5][1][0];
		cube[2][0][2] = cube[5][0][0];
		// 뒤(tmp)3->우5
		cube[5][0][0] = tmp[0];
		cube[5][1][0] = tmp[1];
		cube[5][2][0] = tmp[2];
	}
	else { // 반시계 방향
		// 뒤3 <- 우5
		cube[3][2][0] = cube[5][0][0];
		cube[3][2][1] = cube[5][1][0];
		cube[3][2][2] = cube[5][2][0];
		// 우5 <- 앞2
		cube[5][0][0] = cube[2][0][2];
		cube[5][1][0] = cube[2][0][1];
		cube[5][2][0] = cube[2][0][0];
		// 앞2 <- 좌4
		cube[2][0][0] = cube[4][0][2];
		cube[2][0][1] = cube[4][1][2];
		cube[2][0][2] = cube[4][2][2];
		// 좌4 <- 뒤(tmp)3
		cube[4][0][2] = tmp[2];
		cube[4][1][2] = tmp[1];
		cube[4][2][2] = tmp[0];
	}
}

void rotate_side_D(char clock) { // 아래면 회전
	int tmp[3];
	for (int i = 0; i < 3; i++) tmp[i] = cube[3][0][i];

	if (clock == '+') { // 시계 방향
		// 뒤3 <- 우5
		cube[3][0][0] = cube[5][0][2];
		cube[3][0][1] = cube[5][1][2];
		cube[3][0][2] = cube[5][2][2];
		// 우5 <- 앞2
		cube[5][0][2] = cube[2][2][2];
		cube[5][1][2] = cube[2][2][1];
		cube[5][2][2] = cube[2][2][0];
		// 앞2 <- 좌4
		cube[2][2][0] = cube[4][0][0];
		cube[2][2][1] = cube[4][1][0];
		cube[2][2][2] = cube[4][2][0];
		// 좌4 <- 뒤(tmp)
		cube[4][0][0] = tmp[2];
		cube[4][1][0] = tmp[1];
		cube[4][2][0] = tmp[0];
	}
	else { // 반시계 방향
		// 뒤3 <- 좌4
		cube[3][0][0] = cube[4][2][0];
		cube[3][0][1] = cube[4][1][0];
		cube[3][0][2] = cube[4][0][0];
		// 좌4 <- 앞2
		cube[4][0][0] = cube[2][2][0];
		cube[4][1][0] = cube[2][2][1];
		cube[4][2][0] = cube[2][2][2];
		// 앞2 <- 우5
		cube[2][2][0] = cube[5][2][2];
		cube[2][2][1] = cube[5][1][2];
		cube[2][2][2] = cube[5][0][2];
		// 우5 <- 뒤(tmp)
		cube[5][0][2] = tmp[0];
		cube[5][1][2] = tmp[1];
		cube[5][2][2] = tmp[2];
	}
}

void rotate_side_F(char clock) { // 앞면 회전
	int tmp[3];
	for (int i = 0; i < 3; i++) tmp[i] = cube[0][2][i];

	if (clock == '+') { // 시계 방향
		// 상0 <- 좌4
		cube[0][2][0] = cube[4][2][0];
		cube[0][2][1] = cube[4][2][1];
		cube[0][2][2] = cube[4][2][2];
		// 좌4 <- 하1
		cube[4][2][0] = cube[1][2][0];
		cube[4][2][1] = cube[1][2][1];
		cube[4][2][2] = cube[1][2][2];
		// 하1 <- 우5
		cube[1][2][0] = cube[5][2][0];
		cube[1][2][1] = cube[5][2][1];
		cube[1][2][2] = cube[5][2][2];
		// 우5 <- 상(tmp)
		cube[5][2][0] = tmp[0];
		cube[5][2][1] = tmp[1];
		cube[5][2][2] = tmp[2];
	}
	else { // 반시계 방향
		// 상0 <- 우5
		cube[0][2][0] = cube[5][2][0];
		cube[0][2][1] = cube[5][2][1];
		cube[0][2][2] = cube[5][2][2];
		// 우5 <- 하1
		cube[5][2][0] = cube[1][2][0];
		cube[5][2][1] = cube[1][2][1];
		cube[5][2][2] = cube[1][2][2];
		// 하1 <- 좌4
		cube[1][2][0] = cube[4][2][0];
		cube[1][2][1] = cube[4][2][1];
		cube[1][2][2] = cube[4][2][2];
		// 좌4 <- 상(tmp)
		cube[4][2][0] = tmp[0];
		cube[4][2][1] = tmp[1];
		cube[4][2][2] = tmp[2];
	}
}

void rotate_side_B(char clock) { // 뒷면 회전
	int tmp[3];
	for (int i = 0; i < 3; i++) tmp[i] = cube[1][0][i];

	if (clock == '+') { // 시계 방향
		// 하1 <- 좌4
		cube[1][0][0] = cube[4][0][0];
		cube[1][0][1] = cube[4][0][1];
		cube[1][0][2] = cube[4][0][2];
		// 좌4 <- 상0
		cube[4][0][0] = cube[0][0][0];
		cube[4][0][1] = cube[0][0][1];
		cube[4][0][2] = cube[0][0][2];
		// 상0 <- 우5
		cube[0][0][0] = cube[5][0][0];
		cube[0][0][1] = cube[5][0][1];
		cube[0][0][2] = cube[5][0][2];
		// 우5 <- 하(tmp)
		cube[5][0][0] = tmp[0];
		cube[5][0][1] = tmp[1];
		cube[5][0][2] = tmp[2];
	}
	else { // 반시계 방향
		// 하1 <- 우5
		cube[1][0][0] = cube[5][0][0];
		cube[1][0][1] = cube[5][0][1];
		cube[1][0][2] = cube[5][0][2];
		// 우5 <- 상0
		cube[5][0][0] = cube[0][0][0];
		cube[5][0][1] = cube[0][0][1];
		cube[5][0][2] = cube[0][0][2];
		// 상0 <- 좌4
		cube[0][0][0] = cube[4][0][0];
		cube[0][0][1] = cube[4][0][1];
		cube[0][0][2] = cube[4][0][2];
		// 좌4 <- 하(tmp)
		cube[4][0][0] = tmp[0];
		cube[4][0][1] = tmp[1];
		cube[4][0][2] = tmp[2];
	}
}

void rotate_side_L(char clock) { // 왼쪽면 회전
	int tmp[3];
	for (int i = 0; i < 3; i++) tmp[i] = cube[3][i][0];

	if (clock == '+') { // 시계 방향
		// 뒤3 <- 하1
		cube[3][0][0] = cube[1][2][2];
		cube[3][1][0] = cube[1][1][2];
		cube[3][2][0] = cube[1][0][2];
		// 하1 <- 앞2
		cube[1][0][2] = cube[2][2][0];
		cube[1][1][2] = cube[2][1][0];
		cube[1][2][2] = cube[2][0][0];
		// 앞2 <- 상0
		cube[2][0][0] = cube[0][0][0];
		cube[2][1][0] = cube[0][1][0];
		cube[2][2][0] = cube[0][2][0];
		// 상0 <- 뒤(tmp)
		cube[0][0][0] = tmp[0];
		cube[0][1][0] = tmp[1];
		cube[0][2][0] = tmp[2];
	}
	else { // 반시계 방향
		// 뒤3 <- 상0
		cube[3][0][0] = cube[0][0][0];
		cube[3][1][0] = cube[0][1][0];
		cube[3][2][0] = cube[0][2][0];
		// 상0 <- 앞2
		cube[0][0][0] = cube[2][0][0];
		cube[0][1][0] = cube[2][1][0];
		cube[0][2][0] = cube[2][2][0];
		// 앞2 <- 하1
		cube[2][0][0] = cube[1][2][2];
		cube[2][1][0] = cube[1][1][2];
		cube[2][2][0] = cube[1][0][2];
		// 하1 <- 뒤(tmp)
		cube[1][0][2] = tmp[2];
		cube[1][1][2] = tmp[1];
		cube[1][2][2] = tmp[0];
	}
}

void rotate_side_R(char clock) { // 오른쪽면 회전
	int tmp[3];
	for (int i = 0; i < 3; i++) tmp[i] = cube[3][i][2];

	if (clock == '+') { // 시계 방향
		// 뒤3 <- 상0
		cube[3][0][2] = cube[0][0][2];
		cube[3][1][2] = cube[0][1][2];
		cube[3][2][2] = cube[0][2][2];
		// 상0 <- 앞2
		cube[0][0][2] = cube[2][0][2];
		cube[0][1][2] = cube[2][1][2];
		cube[0][2][2] = cube[2][2][2];
		// 앞2 <- 하1
		cube[2][0][2] = cube[1][2][0];
		cube[2][1][2] = cube[1][1][0];
		cube[2][2][2] = cube[1][0][0];
		// 하1 <- 뒤(tmp)
		cube[1][0][0] = tmp[2];
		cube[1][1][0] = tmp[1];
		cube[1][2][0] = tmp[0];
	}
	else { // 반시계 방향
		// 뒤3 <- 하1
		cube[3][0][2] = cube[1][2][0];
		cube[3][1][2] = cube[1][1][0];
		cube[3][2][2] = cube[1][0][0];
		// 하1 <- 앞2
		cube[1][0][0] = cube[2][2][2];
		cube[1][1][0] = cube[2][1][2];
		cube[1][2][0] = cube[2][0][2];
		// 앞2 <- 상0
		cube[2][0][2] = cube[0][0][2];
		cube[2][1][2] = cube[0][1][2];
		cube[2][2][2] = cube[0][2][2];
		// 상0 <- 뒤(tmp)
		cube[0][0][2] = tmp[0];
		cube[0][1][2] = tmp[1];
		cube[0][2][2] = tmp[2];
	}
}

void cubing() {
	int num; cin >> num;
	char c, clock;
	for (int i = 0; i < num; i++) {
		cin >> c >> clock;
		int face;
		switch (c) {
		case 'U': // 뒤(3), 우(5), 앞(2), 좌(4)
			rotate_side_U(clock);
			face = 0;
			break;
		case 'D': // 뒤(3), 좌(4), 앞(2), 우(5)
			rotate_side_D(clock);
			face = 1;
			break;
		case 'F': // 상(0), 우(5), 하(1), 좌(4)
			rotate_side_F(clock);
			face = 2;
			break;
		case 'B': // 하(1), 우(5), 상(0), 좌(4)
			rotate_side_B(clock);
			face = 3;
			break;
		case 'L': // 뒤(3), 상(0), 앞(2), 하(1)
			rotate_side_L(clock);
			face = 4;
			break;
		case 'R': // 뒤(3), 하(1), 앞(2), 상(0)
			rotate_side_R(clock);
			face = 5;
			break;
		}
		rotate_face(face, clock); // 바라보는 면 회전
		
	}
}

// 0: 상(w) / 1: 하(y) / 2: 앞(r) / 3: 뒤(o) / 4: 좌(g) / 5: 우(b)
int main() {
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		init();
		cubing();
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << cube[0][i][j];
			}
			cout << endl;
		}
	}
}

/*
돌리는 면을 회전
돌아가는 면을 4칸 배열로 만들어서 관리 -> clock에 따라서 순회 방향 다르게
tmp로 값 바꾸듯이 바꾸면 될듯

닿아있는(움직이는) 배열은 어떻게 관리?
상하 / 앞뒤 / 좌우 -> 마주보는 면 별로 i의 위치가 같음
*/