#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, s, m;
int ans = -1;
vector<int> v;

bool arr[51][1001];

int main() {
	cin >> n >> s >> m;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		v.push_back(a);
	}

	arr[0][s] = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= 1000; j++) {
			if (!arr[i][j]) continue;
			if (j + v[i] <= m) {
				arr[i + 1][j + v[i]] = true;
			}
			if (j - v[i] >= 0) {
				arr[i + 1][j - v[i]] = true;
			}
		}
	}

	int ans = -1;
	for (int i = 1000; i >= 0; i--) {
		if (arr[n][i]) {
			ans = i;
			break;
		}
	}
	if (ans >= 0) cout << ans;
	else cout << -1;
}