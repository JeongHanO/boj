#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int bucket[51][51];
vector<pair<int, int>> order;
vector<pair<int, int>> cloud;
vector<pair<int, int>> moved_cloud;

int dx[] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
int dy[] = {0, -1, -1, 0, 1, 1, 1, 0, -1};

int ans = 0;

void print_bucket(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << bucket[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

void input(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> bucket[i][j];
        }
    }
    for(int i = 0; i < m; i++){
        int d, s;
        cin >> d >> s;
        order.push_back({d,s});
    }
}

void make_cloud(){ // 물의 양이 2이상이고 이전에 비가 내린 곳이 아니면 구름 생성
    cloud.clear();
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(bucket[i][j] >= 2){ // 물의 양이 2 이상
                pair<int, int> target = {i,j};
                auto it = find(moved_cloud.begin(), moved_cloud.end(), target);
                if(it == moved_cloud.end()){ // 비가 내린 곳이 아님
                    cloud.push_back({i,j});
                    bucket[i][j] -= 2;
                }
            }
        }
    }
}

void move_cloud(int order_num){
    moved_cloud.clear();

    int d = order[order_num].first;
    int s = order[order_num].second;
    for(int i = 0; i < cloud.size(); i++){
        // 모든 구름을 d 방향으로 s만큼 이동
        int nx = cloud[i].first + dx[d] * s;
        int ny = cloud[i].second + dy[d] * s;
        if(nx <= 0) while(nx <= 0) nx += n;
        if(ny <= 0) while(ny <= 0) ny += n;
        if(nx > n) {
            if(nx % n == 0) nx = n;
            else nx = nx % n;
        }
        if(ny > n) {
            if(ny % n == 0) ny = n;
            else ny = ny % n;
        }
        moved_cloud.push_back({nx,ny});
        // 이동 후 바구니에 물 증가
        bucket[nx][ny] += 1;
    }
}

void paste_water(){
    for(int i = 0; i < moved_cloud.size(); i++){
        for(int j = 2; j < 9; j += 2){
            int nx = moved_cloud[i].first + dx[j];
            int ny = moved_cloud[i].second + dy[j];
            if(nx > 0 && nx <= n && ny > 0 && ny <= n){ // 범위 확인
                if(bucket[nx][ny] >= 1){ // 물이 있으면 복사
                    bucket[moved_cloud[i].first][moved_cloud[i].second] += 1;
                }
            }
        }
    }
}

void solve(){
    cloud.push_back({n, 1});
    cloud.push_back({n, 2});
    cloud.push_back({n-1, 1});
    cloud.push_back({n-1, 2});
    for(int i = 0; i < m; i++){
        move_cloud(i);
        paste_water();
        make_cloud();
    }
}

void cnt(){
    int sum = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            sum += bucket[i][j];
        }
    }
    cout << sum;
}

int main(){
    input();
    solve();
    cnt();
    return 0;
}

/*
    - 처음에는 (N, 1), (N, 2), (N-1, 1), (N-1, 2)에 비구름 생성
    - 구름 이동 함수를 통해 구름 이동 후 비 내리기
    - 물복사 버그 함수를 통해 비 내린 곳에 물 증가
    - 비 내린 곳을 제외하고 물의 양이 2 이상인 곳에 구름 생성
    필요 함수: 구름 이동 & 비 내려서 물 증가, 물복사 버그, 구름 생성
*/