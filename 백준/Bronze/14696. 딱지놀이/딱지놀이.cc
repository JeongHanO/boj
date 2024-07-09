#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	cin.ignore();

	for (int i = 0; i < n; i++) {
		int a[5] = { 0, };
		int b[5] = { 0, };
		
		int cnt = 0;
		cin >> cnt;
		for (int j = 0; j < cnt; j++) {
			int tmp; cin >> tmp;
			a[tmp]++;
		}

		cin >> cnt;
		for (int j = 0; j < cnt; j++) {
			int tmp; cin >> tmp;
			b[tmp]++;
		}

		char c = 'D';
		for (int i = 4; i >= 1; i--) {
			if (a[i] > b[i]) {
				c = 'A';
				break;
			}
			else if (a[i] < b[i]) {
				c = 'B';
				break;
			}
		}
		cout << c << endl;
	}
}
