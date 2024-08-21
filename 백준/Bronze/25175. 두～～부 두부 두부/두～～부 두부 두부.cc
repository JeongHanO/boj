#include <iostream>
using namespace std;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	cout << ((m - 1) + (k - 3) % n + n) % n + 1;
}