#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, b, c;
	cin >> n;
	vector<int> room(n);
	for (int i = 0; i < n; i++)
		cin >> room[i];
	cin >> b >> c;

	long long ans = n;
	for (int i = 0; i < n; i++) {
		if (room[i] >= b) {
			if ((room[i]-b) % c == 0) ans+= (room[i]-b) / c;
			else ans += (room[i]-b) / c + 1;
		}
	}
	cout << ans;
}