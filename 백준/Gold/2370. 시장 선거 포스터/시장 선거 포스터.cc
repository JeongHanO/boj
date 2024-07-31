#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int cnt = 0, k = 0;
vector<int> xlist;
vector<pair<int, int>> v;

void solve() {
	int arr[20001] = { 0, };
	int check[20002] = { 0, };

	for (int i = 0; i < n; i++) {
		int l = v[i].first, r = v[i].second;
		for (int j = l; j <= r; j++) {
			arr[j] = i + 1;
		}
	}
	/*
	실제 앞 뒤는 사실 상관 없음. 어쨋든 어떤 칸에 포스터가 있기만 하면 됨
	*/
	for (int i = 0; i < 20001; i++) {
		if (!arr[i]) continue;
		if (check[arr[i]]) continue;
		else {
			check[arr[i]] = 1;
			cnt++;
		}
	}
	
	return;
}

int main() {
	cin >> n;
	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		xlist.push_back(a);
		xlist.push_back(b);
		v.push_back({ a,b });
	}

	sort(xlist.begin(), xlist.end());
	xlist.erase(unique(xlist.begin(), xlist.end()), xlist.end());

	for (int i = 0; i < n; i++) {
		v[i].first = lower_bound(xlist.begin(), xlist.end(), v[i].first) - xlist.begin();
		v[i].second = lower_bound(xlist.begin(), xlist.end(), v[i].second) - xlist.begin();
	}

	k = xlist.back();

	solve();

	cout << cnt;
}