#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 크기가 k인 윈도우를 이동하면서
// 그 사이에 고장난 신호등의 개수를 카운트, 비교
// 가장 작은 값을 출력

int main(){
    int n, k, b;
    cin >> n >> k >> b;
    
    vector<bool> broken(n+1,false);
    queue<int> q;

    for(int i = 0; i < b; i++){
        int a; 
        cin >> a;
        broken[a] = true;
    }

    
    int tmp = 0;
    for(int i = 1; i <= k; i++){
        q.push(broken[i]);
        if(broken[i]){
            tmp++;
        }
    }
    
    int ans = tmp;
    
    for(int i = k+1; i <= n; i++){
        if(q.front()) tmp--;
        q.pop();
        
        if(broken[i]) tmp++;
        q.push(broken[i]);

        ans = min(ans, tmp);
    }    

    cout << ans;
}