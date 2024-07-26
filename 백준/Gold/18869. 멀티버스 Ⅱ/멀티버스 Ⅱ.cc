#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int m, n;

int main() {
	cin >> m >> n;
	vector<vector<pair<int, int>>> v(m, vector<pair<int,int>> (n));

	int a;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a;
			v[i][j] = { a, j };
		}
		sort(v[i].begin(), v[i].end());
	}
	
	int cnt = 0;
	for (int i = 0; i < m-1; i++) {
		for (int j = i+1; j < m; j++) {
			bool equal = true;
			for (int x = 0; x < n; x++) {
				if (v[i][x].second != v[j][x].second) {
					equal = false;
					break;
				}
				else{
					if (x != n - 1) {
						if ((v[i][x].first < v[i][x + 1].first) != (v[j][x].first < v[j][x + 1].first)) {
							equal = false;
							break;
						}
					}

				}
			}
			if (equal) cnt++;
		}
	}
	cout << cnt;
}