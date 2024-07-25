#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int s;
	string n;
	cin >> s >> n;

	vector<vector<char>> v((2 * s + 3), vector<char>((s + 3)*n.length(), ' '));

	for(int i = 0; i < n.length(); i++){
		int x = (s + 3)*i;
		// 가로선
		// 상
		if (n[i] != '1' && n[i] != '4') {
			for (int j = x; j < x+s; j++) {
				v[0][j+1] = '-';
			}
		}

		// 중 
		if (n[i] != '1' && n[i] != '7' && n[i] != '0') {
			for (int j = x; j < x + s; j++) {
				v[(2 * s + 3) / 2][j+1] = '-';
			}
		}

		// 하
		if (n[i] != '1' && n[i] != '4' && n[i] != '7') {
			for (int j = x; j < x + s ; j++) {
				v[2 * s + 2][j+1] = '-';
			}
		}

		// 세로선
		// 좌상
		if (n[i] != '1' && n[i] != '2' && n[i] != '3' && n[i] != '7') {
			for (int i = 1; i < s+1; i++) {
				v[i][x] = '|';
			}
		}
		
		// 좌하
		if (n[i] != '1' && n[i] != '3' && n[i] != '4' && n[i] != '5' && n[i] != '7' && n[i] != '9') {
			for (int i = s+2; i < 2*s + 2; i++) {
				v[i][x] = '|';
			}
		}
		
		// 우상
		if (n[i] != '5' && n[i] != '6') {
			for (int i = 1; i < s + 1; i++) {
				v[i][x+s+1] = '|';
			}
		}
		
		// 우하
		if (n[i] != '2') {
			for (int i = s+2; i < 2*s + 2; i++) {
				v[i][x+s+1] = '|';
			}
		}
	}

	for (int i = 0; i < 2 * s + 3; i++) {
		for (int j = 0; j < (s + 3)*n.length()-1; j++) {
			cout << v[i][j];
		}
		cout << endl;
	}
}

/*
s+2의 가로, 2s+3의 세로

s개의 '-', 2s개의 '|'

0123 4 5678 9 0123 4 5678 9 0
0 - -	
1|   |	
2|   |	
3 - -	
4|   |	
5|   |	
6 - -	

위 가로 X: 1,4
중간 가로 X: 1,7,0
아래 가로 X: 1,4,7

가로 -> 0, s번 빼고 - 삽입

좌상 세로 X: 1,2,3,7
좌하 세로 X: 1,3,4,5,7,9
우상 세로 X: 5,6
우하 세로 X:2

세로 -> 0, s에만 | 삽입

각 숫자별 가로, 세로를 벡터에 넣음
숫자 반복 횟수 * s로 위치 조정
*/

