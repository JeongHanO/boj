#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int a, b;
vector<int> va;

void check(int n){
    int l = 0, r = a-1;
    int mid;
    while(l <= r){
        mid = (l+r)/2;
        if(n == va[mid]){
            printf("1\n");
            return;
        }
        if(n < va[mid]) r = mid-1;
        else l = mid+1;
    }
    printf("0\n");
    return;
}

int main(){
    cin >> a;
    va.assign(a, 0);
    for(int i = 0; i < a; i++){
        scanf("%d\n", &va[i]);
    }

    sort(va.begin(), va.end());

    cin >> b;
    for(int i = 0; i < b; i++){
        int tmp; scanf("%d\n", &tmp);
        check(tmp);
    }

    return 0;
}