#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n; // 이닝 수
int scoring[50][9]; // 이닝에서 얻는 결과
vector<int> player = {1,2,3,4,5,6,7,8}; // 선수 배열 (첫 번째 선수 제외)
int ans = 0;

void play_baseball(){
    do{
        int tmp_score = 0;
        int out = 0; // 아웃 카운트
        int inning = 0; //현재 이닝(0~n-1)
        int player_index = 0; // 선수 순서(0~8)
        int juja = 0; // 진루 주자

        vector<int> tmp_player = player;
        tmp_player.insert(tmp_player.begin()+3, 0); // 1번 선수 4번 타자로 삽입

        while(inning < n){
            if(out == 3){ //3아웃이 되면 아웃 카운트 초기화, 진루 주자 초기화
                inning++;
                out = 0;
                juja = 0;
                continue;
            }
            
            switch(scoring[inning][tmp_player[player_index++]]){
                case 0:
                    out++;
                    break;
                case 1:
                    juja |= 1;
                    juja = (juja << 1);
                    break;
                case 2:
                    juja |= 1;
                    juja = (juja << 2);
                    break;
                case 3:
                    juja |= 1;
                    juja = (juja << 3);
                    break;
                case 4:
                    juja |= 1;
                    juja = (juja << 4);
                    break;
            }

            if(juja & (1<<4)){
                tmp_score++;
                juja &= ~(1<<4);
            }
            if(juja & (1<<5)){
                tmp_score++;
                juja &= ~(1<<5);
            }
            if(juja & (1<<6)){
                tmp_score++;
                juja &= ~(1<<6);
            }
            if(juja & (1<<7)){
                tmp_score++;
                juja &= ~(1<<7);
            }

            if(player_index == 9) player_index = 0;
        }

        if(ans < tmp_score) ans = tmp_score;
    }while(next_permutation(player.begin(), player.end()));
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 9; j++){
            cin >> scoring[i][j];
        }
    }

    play_baseball();

    cout << ans;
    return 0;
}