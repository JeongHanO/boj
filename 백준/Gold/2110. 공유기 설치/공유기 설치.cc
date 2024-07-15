#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	int n, c, ans;
	cin >> n >> c;
	vector<int> v(n);
	
	for (int i = 0; i < n; i++) cin >> v[i];
	sort(v.begin(), v.end());

	int mid;
	int left = 1, right = v[n-1]-v[0];
	while (left <= right) {
		mid = (left + right) / 2;
		int cnt = 1;
		int cur = v[0];
		for (int i = 1; i < n; i++) {
			if (v[i] - mid >= cur) {
				cnt++;
				cur = v[i];
			}
		}
		if (cnt >= c) {
			left = mid + 1;
			ans = mid;
		}
		else right = mid - 1;
	}
	cout << ans;
}