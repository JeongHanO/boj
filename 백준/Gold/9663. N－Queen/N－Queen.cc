#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

int n;
int cnt = 0;
int DAT[30];
int ar1[40]; // \ 대각 (i-j) -> 음수 값이 나올 수 있음 (-n+1 ~ n-1) -> +n 해주면 될듯?
int ar2[40]; // / 대각 (i+j)

void f(int row) {
	if (row == n) {
		cnt++;
		return;
	}
	for (int col = 0; col < n; col++) {
		if (!DAT[col] && !ar1[row-col+n] && !ar2[row+col]) {
			DAT[col] = true;
			ar1[row - col + n] = true;
			ar2[row + col] = true;
			f(row + 1);
			DAT[col] = false;
			ar1[row - col + n] = false;
			ar2[row + col] = false;
		}
	}
}

int main() {
	cin >> n;
	f(0);
	cout << cnt;
}