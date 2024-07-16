#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, ans = 1000000, pt;
int arr[21][21];

// 구역에 따른 인원수 확인
int counting(int x, int y, int d1, int d2) {
	
	vector<int> p(6);
	// 1번 선거구
	for (int i = 0; i <= d1; i++) {
		int nx = x + i;
		int ny = y - i;
		
		for (int j = nx-1; j > 0; j--) { 
			p[1] += arr[j][ny]; 
		}
	}
	for (int i = y - d1-1; i > 0; i--) {
		for (int j = x + d1-1; j > 0; j--) { 
			p[1] += arr[j][i];
		}
	}

	// 2번 선거구
	for (int i = 1; i <= d2; i++) {
		int nx = x + i;
		int ny = y + i;

		for (int j = nx - 1; j > 0; j--) {
			p[2] += arr[j][ny];
		}
	}
	for (int i = y + d2 + 1; i <= n; i++) {
		for (int j = x + d2; j > 0; j--) {
			p[2] += arr[j][i];
		}
	}

	// 3번 선거구
	int ox = x + d1 + d2;
	int oy = y - d1 + d2;
	int cnt = 0;
	for (int i = 1; i <= d2; i++) {
		int nx = ox - i;
		int ny = oy - i;

		for (int j = nx + 1; j <= n; j++) {
			p[3] += arr[j][ny];
			cnt++;
		}
	}
	for (int i = oy - d2 - 1; i > 0; i--) {
		for (int j = ox - d2; j <= n; j++) {
			p[3] += arr[j][i];
			cnt++;
		}
	}

	// 4번 선거구
	for (int i = 0; i <= d1; i++) {
		int nx = ox - i;
		int ny = oy + i;

		for (int j = nx + 1; j <= n; j++) {
			p[4] += arr[j][ny];
		}
	}
	for (int i = oy + d1 + 1; i <= n; i++) {
		for (int j = ox - d1 + 1; j <= n; j++) {
			p[4] += arr[j][i];
		}
	}

	p[5] = pt - p[1] - p[2] - p[3] - p[4];
	
	sort(p.begin(), p.end());
	return p[5]-p[1];
}

// d1, d2에 따른 구역 구분 함수
void dividing(int x, int y) {
	for (int d1 = 1; d1 < n; d1++) {
		for (int d2 = 1; d2 < n; d2++) {
			if (x + d1 + d2 > n || y - d1 < 0 || y + d2 > n) continue;
			ans = min(ans, counting(x, y, d1, d2));
		}
	}

}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			pt += arr[i][j];
		}
		
	for (int i = 1; i < n-2; i++) {
		for (int j = 2; j < n-1; j++) {
			dividing(i, j);
		}
	}
	cout << ans << endl;
}
/*
선거구 인원 차 구하는 방법
-각 선거구에 대한 인원을 배열에 먼저 넣음
-마지막으로 5번 선거구에 대한 인원을 넣음

*/