#include <iostream>
using namespace std;

// 모든 개미가 떨어지는 시간은 마지막 개미가 떨어지는 시간과 같다.
// 가운데를 기준으로 개미끼리 부딪히지 않고 양쪽으로 가서 떨어지면 가장 빠른 케이스.
// 가장 느린 케이스는 개미들이 한 쪽 방향을 보고 갈 때 인지, 
// 가운데 있는 개미가 충돌하면서 왔다갔다 하다가 떨어질 때인지 생각해볼 것.

int main(){
    int t, n, l;
    cin >> t;
    
    for(int i=0;i<t;i++){
       cin >> l >> n;
       int min_time = 0;
       int max_time = 0;
       for(int i=0;i<n;i++){
            int a;
            cin >> a;

            int a_min = min(a,l-a);
            int a_max = max(a,l-a);

            min_time = max(min_time,a_min);
            max_time = max(max_time,a_max);
        }
        cout << min_time << ' ' << max_time << endl;
    }
}