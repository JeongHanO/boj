#include <algorithm>
using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = 0;
    long long sum = 1LL * count * price * (1+count) / 2;
    
    if(sum <= money) return 0;
    else return abs(money - sum);
}