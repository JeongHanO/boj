#include <iostream>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int arr[100];

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int ans = 0;
    for(int i = 0; i < n-2; i++){
        int ans1 = arr[i];
        for(int j = i+1; j < n-1; j++){
            int ans2 = ans1 + arr[j];
            for(int k = j+1; k < n; k++){
                int ans3 = ans2 + arr[k];
                if(ans3 > ans && ans3 < m) {
                    ans = ans3;
                }
                else if (ans3 == m){
                    cout << m << endl;
                    return 0;
                }
            }
        }
    }

    cout << ans;
}