#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool visited[13];
int friends[3]={1,1,1};
int dfs(vector<int> num, int idx, int cnt){
    int sum = 0;
    if(cnt == 3){
        if((friends[0]+friends[1]+friends[2]) == 0){
        sum++;
        cout << friends[0] << " " << friends[1] << " " << friends[2] << endl;
        return sum;
        }
}
    for(int i = idx; i < num.size(); i++){
        if(!visited[i]){
        visited[i] = true;
        friends[cnt] = num[i];
        sum += dfs(num, i+1, cnt+1);
        visited[i] = false;
}
        
        
    }
    return sum;
}

int solution(vector<int> number) {
    return dfs(number,0,0);
}