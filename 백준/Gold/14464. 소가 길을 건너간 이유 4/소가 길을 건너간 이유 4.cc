#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

struct Cow{
    int st, end;
};

struct  cmp{
    bool operator()(Cow a, Cow b){
        if(a.end != b.end) return a.end > b.end;
        return a.st > b.st;
    }
};

bool c_cmp(pair<int, int> a, pair<int, int> b){
    return a.first < b.first;
}

int c, n;
vector<pair<int, bool> > chi;
priority_queue<Cow, vector<Cow>, cmp> cow;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> c >> n;

    int a, b;
    for(int i = 0; i < c; i++){
        cin >> a;
        chi.push_back({a, false});
    }
    
    sort(chi.begin(), chi.end(), c_cmp);

    for(int i = 0; i < n; i++){
        cin >> a >> b;
        cow.push({a,b});
    }

    int ans = 0;
    while(!cow.empty()){
        for(int i = 0; i < c; i++){
            if(chi[i].first >= cow.top().st && chi[i].first <= cow.top().end && chi[i].second == 0){
                ans++;
                chi[i].second = true;
                break;
            }
        }        
        cow.pop();
    }

    cout << ans;
    return 0;
}