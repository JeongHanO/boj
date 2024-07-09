#include <iostream>
#include <queue>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	priority_queue<long long> pq;
	long long n; cin >> n;
	while (n--) {
		int a; cin >> a;
		if (a) {
			pq.push(-a);
		}
		else {
			if (pq.empty()) cout << 0 << '\n';
			else {
				cout << -pq.top() << '\n';
				pq.pop();
			}
		}
	}
}