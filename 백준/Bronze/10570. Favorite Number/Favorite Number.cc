#include <iostream>
using namespace std;

int main() {
	int n, v;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> v;
		int arr[1001] = { 0, };
		for (int j = 0; j < v; j++) {
			int a; cin >> a;
			arr[a]++;
		}
		int cnt = 0;
		int ans;
		for (int i = 1; i < 1001; i++) {
			if (arr[i] > cnt) { cnt = arr[i]; ans = i; }
		}
		cout << ans << endl;
	}
}
