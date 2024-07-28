#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n, k, b;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> k >> b;
	vector<bool> v(n+1);
	int a;
	for (int i = 0; i < b; i++) {
		cin >> a;
		v[a] = true;
	}

	int ans;
	int cnt = 0;
	for (int i = 1; i <= k; i++) {
		if (v[i]) cnt++;
	}

	ans = cnt;

	for (int i = k + 1; i <= n; i++) {
		if (v[i]) cnt++;
		if (v[i - k]) cnt--;
		
		if (cnt < ans) ans = cnt;
	}
	cout << ans;
}