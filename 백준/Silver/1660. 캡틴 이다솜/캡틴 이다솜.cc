#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[300001];

int main() {
	int n;
	cin >> n;

	vector<int> v;
	// 층 별 사면체에 필요한 포탄 개수 합
	for (int i = 0;; i++) {
		int num = i * (i + 1) * (i + 2) / 6;
		if (num > 300000) break;
		v.push_back(num);
	}

	fill(dp, dp + 300001, 10000000);
	
	// 사면체를 하나씩 쌓기
	for (int i = 0; i < v.size(); i++) {
		dp[v[i]] = 1;
	}

	for (int i = 0; i < v.size(); i++) {
		for (int j = v[i]; j <= n; j++) {
			dp[j] = min(dp[j], dp[j - v[i]] + 1);
		}
	}
	cout << dp[n];
}

/*
0부터 n까지 포탄을 쌓을 때 필요한 최소 사면체의 개수를 카운트.
x번째를 쌓을 때, a층 사면체를 쌓을지 말지 비교.
*/