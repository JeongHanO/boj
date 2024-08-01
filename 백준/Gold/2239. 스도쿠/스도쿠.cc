#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n;
string s;
bool found;
int board[10][10];
vector<pair<int, int>> zero; // 0인 좌표들의 배열

bool rows[10][10]; // i열에 j숫자가 있는지
bool cols[10][10]; // i행에 j숫자가 있는지
bool boxs[10][10]; // i번째 박스에 j숫자가 있는지

void print() {
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			cout << board[i][j];
		}
		cout << endl;
	}
}

void solve(int idx) {
	if (found) return; // 이미 찾았으면 탐색 X
	if (idx == zero.size()) {
		print();
		found = true;
		return;
	}
	int x = zero[idx].first;
	int y = zero[idx].second;
	// 칸에 넣을 수 있는 숫자 찾기
	for (int i = 1; i <= 9; i++) {
		if (rows[x][i] || cols[y][i] || boxs[((x - 1) / 3) * 3 + ((y - 1) / 3 + 1)][i]) continue;
		//숫자 넣기 + DAT 처리
		board[x][y] = i;
		rows[x][i] = true;
		cols[y][i] = true;
		boxs[((x - 1) / 3) * 3 + ((y - 1) / 3 + 1)][i] = true;
		solve(idx + 1);
		board[x][y] = 0;
		rows[x][i] = false;
		cols[y][i] = false;
		boxs[((x - 1) / 3) * 3 + ((y - 1) / 3 + 1)][i] = false;
	}
}

int main() {
	for (int i = 1; i <= 9; i++) {
		cin >> s;
		for (int j = 1; j <= 9; j++) {
			n = s[j-1] - '0';
			board[i][j] = n;
			if (n == 0) { // 0인 칸이면
				zero.push_back({ i, j });
			}
			else { // 숫자가 존재하는 칸이면
				//DAT에 기록
				rows[i][n] = true;
				cols[j][n] = true;
				boxs[((i-1)/3) * 3 + ((j-1)/3+1)][n] = true;
				// 박스는 1~9번 박스
			}
		}
	}
	
	solve(0);
}

/*
0인 칸을 순회하면서 값을 넣어보고 괜찮으면 다음 칸으로 진행

넣을 값은 어떻게 판단?
행, 열, 박스에 어떤 숫자가 있는지 DAT에 저장해놓고 순회
bool rows[i][j] // i열에 j숫자가 있는지
bool cols[i][j] // i행에 j숫자가 있는지
bool boxs[i][j] // i번째 박스에 j숫자가 있는지
*/