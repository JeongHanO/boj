#include <iostream>
#include <string>
using namespace std;

int n, m;
int a[50][50];
int b[50][50];

int main() {
	cin >> n >> m;
	cin.ignore();

	string str;
	for (int i = 0; i < n; i++) {
		getline(cin, str);
		for (int j = 0; j < m; j++) {
			a[i][j] = str[j] - '0';
		}
	}

	for (int i = 0; i < n; i++) {
		getline(cin, str);
		for (int j = 0; j < m; j++) {
			b[i][j] = str[j] - '0';
		}
	}
	
	int cnt = 0;
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 2; j++) {
			if (a[i][j] != b[i][j]) {
				for (int x = 0; x < 3; x++) {
					for (int y = 0; y < 3; y++) {
						a[i + x][j + y] = !a[i + x][j + y];
					}
				}
				cnt++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] != b[i][j]) {
				cout << -1;
				return 0;
			}
		}
	}

	cout << cnt << endl;
	return 0;
}