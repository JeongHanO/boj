#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<int> v, int nums[], int index, int depth){
    if(index == 6){
        for(int i = 0; i < 6; i++){
            cout << nums[i] << ' ';
        }
        cout << '\n';
        return;
    }
    if(depth == v.size()){
        return;
    }


    nums[index] = v[depth];
    dfs(v, nums, index+1, depth+1);
    
    dfs(v, nums, index, depth+1);

    return;
}

int main(){
    while(true){
        int k;
        cin >> k;
        
        if(k == 0){
            return 0;
        }

        vector<int> v(k);

        for(int i = 0; i < k; i++){
            int a;
            cin >> a;
            v[i] = a;
        }

        int nums[6];
        dfs(v, nums, 0, 0);
        cout << '\n';
    }
}