#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> sum(n+1, 0);
	sum[0] = 0;
	for(int i = 1; i <= n; i++){
		int a;
		cin >> a;
		sum[i] = a + sum[i - 1];
	}

	while (m--) {
		int i, j;
		cin >> i >> j;
		cout << sum[j]-sum[i-1] << '\n';
	}

	return 0;
}