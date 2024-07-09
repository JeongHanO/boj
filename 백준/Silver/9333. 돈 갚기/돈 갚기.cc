#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n;
	cin >> n;
	while (n--) {
		double r, b, m;
		cin >> r >> b >> m;
		int month = 1;

		// 변수를 센트 단위로 변환
		long long balance = round(b * 100);
		long long rate = round(r * 100);
		long long monthly_payment = round(m * 100);

		while (month <= 1200) {
			// 이자 계산을 더 정확하게
			long long interest = (balance * rate + 5000) / 10000; // 반올림을 위해 5000을 더함
			balance += interest;
			balance -= monthly_payment;
			if (balance <= 0) break;
			month++;
		}
		if (month <= 1200) cout << month << endl;
		else cout << "impossible" << endl;
	}
	return 0;
}
