#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int city[101][101];

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) city[i][j] = 1e8;
		}
	}

	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		city[a][b] = min(city[a][b], c);
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (city[i][j] > city[i][k] + city[k][j]) {
					city[i][j] = city[i][k] + city[k][j];
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) cout << "0 ";
			else if(city[i][j] == 1e8) cout << "0 ";
			else cout << city[i][j] << ' ';
		}
		cout << endl;
	}
}