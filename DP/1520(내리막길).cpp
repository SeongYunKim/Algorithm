/*
 * 날짜: 2021-03-01
 * 분류: DFS, DP
 * TIP: https://wootool.tistory.com/83
 * 도착지에서 1을 반환하며 거꾸로 DP 배열을 채우기
 * 한 번 방문했던 곳은 다시 검사하지 않기
 */

#include <iostream>
#pragma warning (disable: 4996)

using namespace std;

int N, M;
int board[502][502] = {0};
int dp[502][502] = {0};
bool visited[502][502] = {0};
int moveX[4] = {1, -1, 0, 0};
int moveY[4] = {0, 0, 1, -1};

int dfs(int x, int y) {
    if (x == N && y == M)
        return 1;

    if (!visited[x][y]) {
        visited[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int nextX = x + moveX[i];
            int nextY = y + moveY[i];
            if (board[nextX][nextY] == 0)
                continue;
            if (board[nextX][nextY] < board[x][y]) {
                dp[x][y] += dfs(nextX, nextY);
            }
        }
    }

    return dp[x][y];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> board[i][j];
        }
    }

    cout << dfs(1, 1);

    return 0;
}