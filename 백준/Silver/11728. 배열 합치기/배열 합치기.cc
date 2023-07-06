#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    int a;
    cin >> n >> m;
    vector<int> v1;
    vector<int> v2;
    for(int i = 0; i < n; i++){
        cin >> a;
        v1.push_back(a);
    }
    for(int i = 0; i < m; i++){
        cin >> a;
        v2.push_back(a);
    }
    for(int i = 0; i < m; i++){
        v1.push_back(v2[i]);
    }
    sort(v1.begin(), v1.end());
    for(int i : v1){
        cout << i << ' ';
    }
}