#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    
    vector<vector<int>> v(n+1, vector<int>(n+1));
    int max_num = (n*(n+1)/2);
    int x = 0, y = 0;

    int state = 0;
    int num = 1;
    
    for(int i=0; i<n; i++) {
        switch(state) {
            case 0:
                for(int k=i; k<n; k++) { v[x++][y] = num++; }
                x--;
                y++;
                state = 1;
                break;
            case 1:
                for(int k=i; k<n; k++) { v[x][y++] = num++; }
                x--;
                y-=2;
                state = 2;
                break;
            case 2:
                for(int k=i; k<n; k++) { v[x--][y--] = num++; }
                x+=2;
                y++;
                state = 0;
                break;
        }
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            answer.push_back(v[i][j]);
        }
    }
    
    return answer;
}

/*
3가지 움직임 필요.
1. 수직으로 내려오면서 숫자 하나씩 증가.
2. 내려오다 마지막 줄에 위치하면 오른쪽으로 움직이면서 숫자 하나씩 증가.
3. 끝까지 도달하면 왼쪽 상단으로 움직이면서 숫자 하나씩 증가.
*/

/*
1            
2  12        
3  13 11     
4  14 15 10
5  6  7  8  9
*/