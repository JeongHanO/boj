#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int a, b;
vector<int> va;
vector<int> vb;

bool check(int i){
    int n = va[i];
    int l = 0, r = b-1;
    int mid;
    while(l <= r){
        mid = (l+r)/2;
        if(n == vb[mid]) return false;
        if(n < vb[mid]) r = mid-1;
        else l = mid+1;
    }
    return true;
}

int main(){
    vector<int> ans;

    cin >> a >> b;
    for(int i = 0; i < a; i++){
        int tmp; cin >> tmp;
        va.push_back(tmp);
    }


    for(int i = 0; i < b; i++){
        int tmp; cin >> tmp;
        vb.push_back(tmp);
    }

    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());

    for(int i = 0; i < a; i++){
        if(check(i)) ans.push_back(va[i]);
    }

    cout << ans.size() << endl;
    if(!ans.empty()){
        for(auto i: ans){
            cout << i << ' ';
        }
    }
}