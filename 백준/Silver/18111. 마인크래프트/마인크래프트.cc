#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, b;
int block[500][500]={ 0, };
int height[257] = { 0, };

int main(){
    cin >> n >> m >> b;
    int min_height = 257;
    int max_height = -1;
    for(int i=0;i<n*m;i++){
            int a;
            cin >> a;
            height[a]++;
            if(a < min_height){
                min_height = a;
            }
            if(a > max_height){
                max_height = a;
            }
    }
    
    int time[257];
    fill_n(time,257,99999999);
    for(int i = 0; i <= 256; i++){ // i 는 기준이 되는 높이
        time[i] = 0;
        int block = b;
        for(int j = min_height; j <= max_height; j++){ // j는 i(기준)와 비교할 높이
            
            if(i==j){ continue; } //높이가 같으면 추가 동작이 필요 없음
            else if (i>j){ // 기준점이 블록의 높이보다 높으면 블럭을 쌓아야함
                // 블럭 쌓는 시간 = 쌓아야 하는 블럭의 개수(기준점 높이 - 비교 높이) * 1초 * 비교하는 높이 블럭의 개수
                time[i] += (i-j) * 1 * height[j];
                block -= height[j]*(i-j);
            }
            else{ // 기준점이 블록의 높이보다 낮으면 블럭을 깍아야함
                // 블럭 깍는 시간 = 깍아야 하는 블럭의 개수(비교 높이 - 기준점 높이) * 2초 * 비교하는 높이 블럭의 개수
                time[i] += (j-i) * 2 * height[j];
                block += height[j]*(j-i);
            }
            
        }
        if(block<0){ // 쌓아야하는 블럭의 개수가 부족하면 취소해야함.
            time[i] = 999999999;
        }
    }

    int tmp = 999999999;
    int idx = 0;

    for(int i=0; i < 257; i++){
        if(time[i] <= tmp){
            tmp = time[i];
            idx = i;
        }
    }
    
    cout << tmp << ' ' << idx;
}
