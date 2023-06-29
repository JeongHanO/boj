#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)
#include <iostream>
#include <string>
#define endl '\n'
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	while (1) {
		string st;
		getline(cin, st);
		if (st == "#") { break; }
		int num = 0;
		for (int i = 0; i < st.length(); i++) {
			if (st[i] == 'a' || st[i] == 'e' || st[i] == 'i' || st[i] == 'o' || st[i] == 'u') {
				num++;
			}
			else if (st[i] == 'A' || st[i] == 'E' || st[i] == 'I' || st[i] == 'O' || st[i] == 'U') {
				num++;
			}
		}
		cout << num << endl;
	}
}