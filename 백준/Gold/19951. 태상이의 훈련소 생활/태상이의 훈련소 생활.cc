#include <iostream>
#include <vector>
using namespace std;

int height[100001];

int ord[100002];

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) cin >> height[i];
	
	int a, b, k;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> k;
		ord[a] += k;
		ord[b+1] -= k;
	}

	int sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += ord[i];
		height[i] += sum;
	}

	for (int i = 1; i <= n; i++) cout << height[i] << ' ';
}