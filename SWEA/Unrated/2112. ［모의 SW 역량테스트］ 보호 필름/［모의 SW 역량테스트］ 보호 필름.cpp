#include <iostream>
#include <algorithm>

using namespace std;

int T;
int D, W, K;
int MN;		// 최소 약품 투입 개수

int arr[15][22];

bool isValid() {
	// K개 통과했는지 검사
	for (int col = 0; col < W; col++) {
		int prev = arr[0][col];
		int cnt = 1;		// 같은 특성 개수
		int mx_cnt = 1;		// 한 열에서 같은 특성 최대 연속 개수
		for (int row = 1; row < D; row++) {
			int now = arr[row][col];

			// 이전 값과 똑같으면
			if (now == prev) {
				cnt++;
				mx_cnt = max(mx_cnt, cnt);
			}
			
			// 이전 값과 다르면
			else {
				prev = now;
				cnt = 1;
			}
		}
		
		// 한 열 모두 검사 후 K개 미만이면 false 반환
		if (mx_cnt < K) return false;
	}
	// return되지 않았다면 모두 K개 이상이므로 true 반환
	return true;
}

void dfs(int row, int drug) {
	if (drug >= MN) return; // 가지치기
	if (row == D) {
		if (isValid()) {
			// 최소 약품 투입 갱신
			MN = min(MN, drug);
		}
		return;
	}

	// 안바꿈
	dfs(row + 1, drug);

	// row번을 A로
	int tmp[20] = {};
	for (int col = 0; col < W; col++) {
		tmp[col] = arr[row][col];
		arr[row][col] = 0;
	}
	dfs(row + 1, drug+1);
	for (int col = 0; col < W; col++) {
		arr[row][col] = tmp[col];
	}

	// row번을 B로
	for (int col = 0; col < W; col++) {
		tmp[col] = arr[row][col];
		arr[row][col] = 1;
	}
	dfs(row + 1, drug+1);
	for (int col = 0; col < W; col++) {
		arr[row][col] = tmp[col];
	}
}

int solve() {
	// 최소 약품 수 초기화.
	MN = 1000000; // 최대 D번 약품투입 가능함.

	// 재귀 실행
	dfs(0, 0); // 0행, 약품 투입 0번

	return MN;
}

int main() {
	cin >> T;

	for (int testcase = 1; testcase <= T; testcase++) {
		cin >> D >> W >> K;
		for (int i = 0; i < D; i++) {
			for (int j = 0; j < W; j++) {
				cin >> arr[i][j];
			}
		}

		int answer = solve();

		cout << "#" << testcase << " " << answer << '\n';
	}
	
	return 0;
}