#include <iostream>
#include <algorithm>
using namespace std;

int n, m, r;
int area[101];
int arr[101][101];

void floyd() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (arr[i][j] > arr[i][k] + arr[k][j]) {
					arr[i][j] = arr[i][k] + arr[k][j];
				}
			}
		}
	}
}

int main() {
	cin >> n >> m >> r;

	for (int i = 1; i <= n; i++) {
		int t; cin >> t;
		area[i] = t;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) arr[i][j] = 1e8;
		}
	}
	
	int a, b, l;
	for (int i = 1; i <= r; i++) {
		cin >> a >> b >> l;
		arr[a][b] = l;
		arr[b][a] = l;
	}

	floyd();

	int ans = 0;
	for (int i = 1; i <= n; i++) { // i = 처음 떨어진 위치
		int tmp = area[i];
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			if (arr[i][j] <= m) {
				tmp += area[j];
			}
		}
		ans = max(ans, tmp);
	}
	
	cout << ans;
}