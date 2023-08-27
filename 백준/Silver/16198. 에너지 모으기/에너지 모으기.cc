#include <iostream>
#include <vector>
using namespace std;

int bigger(int a, int b){if(a>b) return a; return b;}
int energy = 0;


void calc(vector<int> w, int weight){
    if(w.size() == 3){
        weight += w[0] * w[2];
        energy = bigger(weight, energy);
        return;
    }

    for(int i = 1; i < w.size() - 1; i++){
        vector<int> tmpW = w;
        tmpW.erase(tmpW.begin() + i);
        calc(tmpW, weight + (w[i-1] * w[i+1]));
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    vector<int> w;
    cin >> n;

    for(int i = 0;i < n ;i++){
        int a;
        cin >> a;
        w.push_back(a);
    }

    calc(w, 0);

    cout << energy;
    return 0;
}
