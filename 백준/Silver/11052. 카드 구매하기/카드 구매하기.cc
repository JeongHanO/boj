#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> p(n+1);
    vector<int> cost(n+1,0);
    for (int i = 1; i < n+1; i++)
    {
        cin >> p[i];
    }
    cost[1] = p[1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j > 0; j--)
        {
            cost[i] = max(cost[i], cost[i-j]+p[j]);
        }
    }
    cout << cost[cost.size()-1]<<endl;
    return 0;
}