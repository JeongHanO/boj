#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	int a = 1;
	cin >> n;

	while (true) {
		cin >> a;
		if (a == 0) break;
		if (a % n == 0 && a >= n) cout << a << " is a multiple of " << n << ".\n";
		else cout << a << " is NOT a multiple of " << n << ".\n";
	}
}