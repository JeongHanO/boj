#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int V, E;
int ans = 1e9;
int arr[401][401];

void floyd() {
	for (int k = 1; k <= V; k++) {
		for (int i = 1; i <= V; i++) {
			for (int j = 1; j <= V; j++) {
				if (arr[i][j] > arr[i][k] + arr[k][j]) {
					arr[i][j] = arr[i][k] + arr[k][j];
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> V >> E;

	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			if (i != j) arr[i][j] = 1e9;
		}
	}

	int a, b, c;
	for (int i = 0; i < E; i++) {
		cin >> a >> b >> c;
		arr[a][b] = c;
	}

	floyd();

	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			if (i == j) continue;
			ans = min(ans, arr[i][j] + arr[j][i]);
		}
	}

	cout << (ans == 1e9 ? -1 : ans);
}