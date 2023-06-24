#include <iostream>
#include <string>
using namespace std;
int main() {
	ios::sync_with_stdio(false), cin.tie(NULL);
	string K;
	register int L;
	cin >> K >> L;
	for (register int i = 2, j; i < L; ++i) {
		register int ans = 0, tmp = 1;
		for (j = K.length() - 1; j >= 0; --j) {
			ans = (ans + (K[j] - '0') * tmp) % i;
			tmp *= 10;
			tmp %= i;
		}
		if (ans == 0) {
			cout << "BAD " << i;
			return 0;
		}
	}
	cout << "GOOD";
	return 0;
}
