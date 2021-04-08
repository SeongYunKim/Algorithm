/*
 * 날짜: 2021-04-09
 * 분류: DFS, Greedy
 * TIP: / - \ 방향 차례대로 오른쪽으로 Greedy하게 DFS
 * 전역 변수 없이 DFS 함수 종료하는 법: bool을 true로 반환
 */

#include <iostream>
#include <string>

#pragma warning (disable: 4996)

using namespace std;

int R, C;
char board[10002][502] = {0};
bool visited[10002][502] = {false};
int moveY[3] = {-1, 0, 1};
int result = 0;

bool dfs(int curY, int curX) {
    if (curX == C) {
        result++;
        return true;
    }
    for (int i = 0; i < 3; i++) {
        int nextY = curY + moveY[i];
        int nextX = curX + 1;
        if (nextY == 0 || nextY == R + 1)
            continue;
        if (board[nextY][nextX] == 'x' || visited[nextY][nextX])
            continue;
        visited[nextY][nextX] = true;
        bool flag = dfs(nextY, nextX);
        if (flag) return flag;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> R >> C;
    string s;
    for (int i = 1; i <= R; i++) {
        cin >> s;
        for (int j = 0; j < C; j++)
            board[i][j + 1] = s[j];
    }

    for (int i = 1; i <= R; i++)
        dfs(i, 1);

    cout << result;
    return 0;
}