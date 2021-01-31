/*
 날짜: 2021-01-30
 분류: BFS, 비트마스킹
 TIP: 현재 보유하고 있는 키를 비트마스킹을 사용해 표현
 */

#include <iostream>
#include <queue>

#pragma warning (disable: 4996)

using namespace std;

int N, M;
char board[52][52] = {0};
bool visited[52][52][36] = {0};
queue<pair<pair<int, int>, pair<int, int>>> q;
int moveX[4] = {-1, 1, 0, 0};
int moveY[4] = {0, 0, -1, 1};
int startX, startY;

int bfs(int startX, int startY) {
    q.push({{startX, startY},
            {0,      0}});

    while (!q.empty()) {
        int curX = q.front().first.first;
        int curY = q.front().first.second;
        int curBit = q.front().second.first;
        int curDist = q.front().second.second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nextX = curX + moveX[i];
            int nextY = curY + moveY[i];
            char nextBoard = board[nextX][nextY];
            if (nextBoard == '1')
                return curDist + 1;
            else if (nextBoard == '#' || visited[nextX][nextY][curBit])
                continue;
            if (nextBoard >= 'A' && nextBoard <= 'F') {
                if (curBit & (1 << nextBoard - 'A')) {
                    visited[nextX][nextY][curBit] = true;
                    q.push({{nextX,     nextY},
                            {curBit, curDist + 1}});
                }
            } else if (nextBoard == '.' || nextBoard == '0') {
                visited[nextX][nextY][curBit] = true;
                q.push({{nextX,  nextY},
                        {curBit, curDist + 1}});
            } else if (nextBoard >= 'a' && nextBoard <= 'f') {
                int newBit = curBit | (1 << nextBoard - 'a');
                if (!visited[nextX][nextY][newBit]) {
                    visited[nextX][nextY][newBit] = true;
                    q.push({{nextX,  nextY},
                            {newBit, curDist + 1}});
                }

            }

        }
    }

    return -1;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 52; i++) {
        for (int j = 0; j < 52; j++) {
            board[i][j] = '#';
        }
    }

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> board[i][j];
            if (board[i][j] == '0') {
                startX = i;
                startY = j;
            }
        }
    }

    cout << bfs(startX, startY);
}
