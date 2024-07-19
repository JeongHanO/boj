#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int low = 2000000001;
	pair<int, int> ans;
	for (int i = 0; i < n; i++) {
		
		int left = i+1, right = n - 1;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (v[mid] + v[i] == 0) {
				cout << min(v[mid], v[i]) << ' ' << max(v[mid], v[i]);
				return 0;
			}
			else if (v[mid] + v[i] > 0) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
			
			if (abs(v[mid] + v[i]) < low) {
				low = abs(v[mid] + v[i]);
				ans = { min(v[mid],v[i]), max(v[mid],v[i]) };
			}
		}
	}
	cout << ans.first << ' ' << ans.second;
}

/*
n이 최대 100,000이니까 O(n^2)은 안됨
for문 하나에 이분탐색이면 O(nlogn)

한 개를 골라서 비교하면 어차피 그 값은 이제 더 필요 없어짐
그럼 그냥 vector에서 빼면 됨
굳이 빼지 않아도 탐색 조건에서만 빼면 됨
left = i로 둬서 더이상 탐색하지 않도록 함
*/