#include <iostream>
#include <vector>
using namespace std;

int n;
int room[21][21];
vector<int> order;
vector<int> fav[401];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

pair<int, int> count(int order, int x, int y) { // 특정 칸에 인접한 친구 수, 빈칸 수 반환
    int friends = 0;
    int empty = 0;
    /*cout << " order : " << order << endl;*/
    for (int i = 0; i < 4; i++) {
        // 인접한 칸이 유효한 범위인지 판단하고 카운트
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx > 0 && nx <= n && ny > 0 && ny <= n) {
            if (room[nx][ny] == 0) { // 빈칸이면
                empty++;
                continue;
            }
            for (int j = 0; j < 4; j++) {
                if (room[nx][ny] == fav[order][j]) { // 좋아하는 친구가 있는 칸이면
                    friends++;
                    break;
                }
            }
            
        }
    }
    return make_pair(friends, empty);
}

void placement(int stu_num) {
    int friends = 0;
    int empty = 0;
    pair<int, int> place = {-1,-1};
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (room[i][j] != 0) continue; // 이미 자리에 사람 있으면 통과
            pair<int, int> cnt = count(stu_num, i, j);
            if (cnt.first > friends) { //친구 수가 가장 많은 칸이면
                // 가장 많은 친구 수 갱신, 빈칸 수 갱신, xy 후보값 갱신
                friends = cnt.first;
                empty = cnt.second;
                place = make_pair(i, j);
            }
            else if (cnt.first == friends) { //친구 수가 최대와 같은 칸이면
                if (cnt.second > empty) { // 빈칸 수가 기존보다 많다면
                    // 빈칸 수 갱신, xy 후보값 갱신
                    empty = cnt.second;
                    place = make_pair(i, j);
                }
                if (place.first == -1 && place.second == -1) {
                    place = make_pair(i, j);
                }
            }
            else if (place.first == -1 && place.second == -1) {
                place = make_pair(i, j);
            }
        }
    }

    
    //cout << endl;
    //cout << endl;
    //cout << "sn : " << stu_num << "Pf : " << place.first << " / Ps : " << place.second << endl;
    room[place.first][place.second] = stu_num;

    // 현재 만족하는 값이 없는 칸에 들어가지 않음.

    /*cout << "stu_num : " << stu_num << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << room[i][j] << ' ';
        }
        cout << endl;
    }*/
}

int main() {
    cin >> n;
    for (int i = 0; i < n * n; i++) {
        int a; cin >> a;
        order.push_back(a);
        for (int j = 0; j < 4; j++) {
            int b; cin >> b;
            fav[a].push_back(b);
        }
    }

    for (int i = 0; i < n * n; i++) {
        int stu_num = order[i];
        placement(stu_num);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            pair<int, int> cnt = count(room[i][j], i, j);
            int sum = 0;
            switch (cnt.first) {
                case 0:
                    sum = 0;
                    break;
                case 1:
                    sum = 1;
                    break;
                case 2:
                    sum = 10;
                    break;
                case 3:
                    sum = 100;
                    break;
                case 4:
                    sum = 1000;
                    break;
            }
            ans += sum;
        }
    }

    cout << ans;
    return 0;
}

/*
1. 번호 순서대로 돌면서 자리 배정
2. 비어있는 칸 중 좋아하는 학생이 가장 많은 자리 -> 브루트 포스로 탐색하면서 x,y값 찾기(0,0부터 시작해서 기록)
3. 위 조건을 만족하면 비어있는 칸이 많은 자리로.

필요한 값: 좋아하는 학생 명수, xy기준 비어있는 칸의 수, xy값
좋아하는 학생 명수가 가장 많은 xy칸과 비어있는 칸을 기록한 vector<pair<int, <pair<int, int>> 선언.
vector를 비어있는 칸의 수로 sort한 뒤, xy값으로 재정렬하면 제일 앞의 값을 사용하면 됨

pair<int, int> map[21][21]을 선언해서 1,1부터 각 칸에 좋아하는 학생수, 비어있는 칸 수를 세고 그 값을 저장 및 비고하는 방식
*/