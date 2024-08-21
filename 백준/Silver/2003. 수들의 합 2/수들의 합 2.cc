#include <iostream>

using namespace std;

// M MAX 3억
int N;
int M;
int maps[10001];

int main()
{
	/*
	투포인터 세그먼트 윈도우슬라이딩
	"연속된 구간 힌트" 
	M이 되는 합
	*/
	cin >> N >> M;




	for (int i = 0; i < N; i++)
	{
		cin >> maps[i];
	}


	/*
		1. L<N
		2. R>L 
	*/
	int left = 0;
	int right = 0;

	int sums = maps[0];
	int cnt = 0;
	while (true)
	{
		if (right > N) break;
		if (sums == M) {
			cnt++;
		}
		if (sums < M)
		{
			right++;
			sums += maps[right];
		}
		else if (sums >= M)
		{
			sums -= maps[left];
			left++;
		}

	}
	cout << cnt;



	
}