#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,L;
vector<int> v;

int main() {
    cin >> N >> L;
    
    int a;
    for(int i = 0; i < N; i++) {    
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(),v.end());

    int ans=1;
    int tmp=L-1;

    for(int i=0; i < N-1; i++) {
        if(v[i+1] - v[i] <= tmp) {
            tmp -= v[i+1] - v[i];
        } else {
            tmp = L - 1;
            ans++;
        }
    }
    cout << ans;
}