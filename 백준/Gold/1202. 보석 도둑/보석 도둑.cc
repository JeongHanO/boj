#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int n, k;
long long ans = 0;

multiset<int> bag_ms; // 가방 무게
vector<pair<int, int>> j; // 보석 무게, 가격



bool cmp(pair<int, int> a, pair<int, int> b) { // 가격 내림차순 정렬, 무게 오름차순 정렬
	if (a.second == b.second) {
		return a.first < b.first;
	}
	else {
		return a.second > b.second;
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	cin >> n >> k;

	int m, v;
	for (int i = 0; i < n; i++) {
		cin >> m >> v;
		j.push_back({ m,v });
	}

	sort(j.begin(), j.end(), cmp);
	int a;
	for (int i = 0; i < k; i++) {
		cin >> a;
		bag_ms.insert(a);
	}


	for (int i = 0; i < n; i++) {
		if (bag_ms.empty()) break; // 남은 가방 없음
		auto it = bag_ms.lower_bound(j[i].first);
		if (it == bag_ms.end()) continue; //넣을 수 있는 가방 없음
		//cout << "price: " << j[i].second << " / bag_size: " << *it << endl;
		bag_ms.erase(it);
		ans += j[i].second;
	}

	cout << ans;
}