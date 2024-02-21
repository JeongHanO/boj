//2170: 선긋기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<pair<int, int>> v;
	for(int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a, b });
	}

	int ans = 0;
	int start = v[0].first, end = v[0].second;
	for (int i = 1; i < n; i++) {
		if (v[i].first > end) {
			ans += end - start;
			start = v[i].first;
			end = v[i].second;
		}
		else if (v[i].first <= end) {
			if (v[i].second <= end) continue;
			end = v[i].second;
		}
	}

	ans += end - start;

	cout << ans << endl;

	return 0;
}