#include <iostream>
#include <algorithm>
using namespace std;

int ans = 0;
// 가장 길게 연속인 걸 셀 변수

void checkC(char arr[51][51], int size) {
    for (int i = 0; i < size; i++) {
        int count = 1;
        for (int j = 0; j < size; j++) {
            if (arr[i][j] == arr[i][j + 1])
                count++;
            else {
                if (count > ans)
                    ans = count;
                count = 1;
            }
        }
    }
}

void checkR(char arr[51][51], int size) {
    for (int i = 0; i < size; i++) {
        int count = 1;
        for (int j = 0; j < size; j++) {
            if (arr[j][i] == arr[j + 1][i])
                count++;
            else {
                if (count > ans)
                    ans = count;
                count = 1;
            }
        }
    }
}

int main() {
    int n = 0;
    char board[51][51];

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            swap(board[i][j], board[i][j + 1]);

            checkR(board, n);
            checkC(board, n);

            swap(board[i][j + 1], board[i][j]);

            swap(board[j][i], board[j + 1][i]);

            checkR(board, n);
            checkC(board, n);

            swap(board[j][i], board[j + 1][i]);
        }
    }

    cout << ans << endl;
}