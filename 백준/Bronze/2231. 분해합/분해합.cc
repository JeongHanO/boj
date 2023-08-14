#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    for (int i = n / 2; i < n; i++){
        int tmp = i;
        int sum = 0;
        while(tmp > 0){
            sum += tmp % 10;
            tmp /= 10;
        }
        if(i + sum == n){
            cout << i;
            return 0;
        }
    }
    cout << 0;
    return 0;
}