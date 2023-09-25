#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <iostream>
using namespace std;


vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> ans(n, "");
    
    int a = n;
    for(int i = 0; i < arr1.size(); i++){
        bitset<16> bit(arr1[i]);
        string s = "";
        for(int j = n-1; j >= 0 ; j--){
            char c;
            if(bit[j] == 1) c = '#';
            else c = ' ';
            s += c;
        }
        ans[i] = s;
    }
    
    for(int i = 0; i < arr2.size(); i++){
        bitset<16> bit(arr2[i]);
        for(int j = n-1; j >= 0 ; j--){
            if(bit[j] == 1 && ans[i][n-j-1] == ' ') ans[i][n-j-1] = '#';
        }
    }
    
    return ans;
}