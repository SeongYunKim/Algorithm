/*
 * 날짜: 2021-04-22
 * 분류: DFS, DP
 * TIP:
 * 무한 움직일 수 있는 경우 => DFS visited true인 곳에 재방문하는 경우
 * (처음에는 BFS 순회하며 visited 배열을 체크했지만, BFS의 visited는 다른 경로 중 방문했을 수도 있음)
 *
 * 단순 DFS는 시간 초과 발생, DP를 활용해 반복적 탐색을 회피
 * dp[x][y]: (x, y)에서 최대 움직일 수 있는 횟수
 */

#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

#pragma warning (disable: 4996)

using namespace std;

int N, M;
int board[52][52] = {0};
int dp[52][52] = {0};
bool visited[52][52] = {false};
int moveX[4] = {1, -1, 0, 0};
int moveY[4] = {0, 0, 1, -1};

int dfs(int curX, int curY) {
    if (curX < 1 || curY < 1 || curX > N || curY > M || board[curX][curY] == -1)
        return 0;
    if (visited[curX][curY]) {
        cout << -1;
        exit(0);
    }
    if (dp[curX][curY] != -1) return dp[curX][curY];

    visited[curX][curY] = true;
    dp[curX][curY] = 0;
    for (int i = 0; i < 4; i++) {
        int nextX = curX + moveX[i] * board[curX][curY];
        int nextY = curY + moveY[i] * board[curX][curY];
        dp[curX][curY] = max(dp[curX][curY], dfs(nextX, nextY) + 1);
    }
    visited[curX][curY] = false;
    return dp[curX][curY];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp, -1, sizeof dp);
    cin >> N >> M;
    string s;
    for (int i = 1; i <= N; i++) {
        cin >> s;
        for (int j = 1; j <= M; j++) {
            if (s[j - 1] != 'H')
                board[i][j] = s[j - 1] - '0';
            else
                board[i][j] = -1;
        }
    }
    cout << dfs(1, 1);
    return 0;
}
