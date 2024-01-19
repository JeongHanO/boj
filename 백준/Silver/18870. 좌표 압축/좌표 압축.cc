#include <vector>
#include <algorithm>
#include <set>
#include <iostream>
using namespace std;

int a;
vector<int> v;

int main(){
    cin >> a;
    v.assign(a, 0);

    for(int i = 0; i < a; i++){
        scanf("%d", &v[i]);
    }
    set<int> s;
    for(int i = 0; i < a; i++){
        s.insert(v[i]);
    }
    vector<int> v1(s.begin(), s.end());
    int size = v1.size()-1;

    for(int i = 0; i < a; i++){
        int l = 0, r = size;
        int mid;
        while(l <= r){
            mid = (l+r)/2;
            if(v1[mid] == v[i]){
                cout << mid << ' ';
                break;
            }
            if(v1[mid] > v[i]){
                r = mid - 1;
            }
            else l = mid +1;
        }
    }
}