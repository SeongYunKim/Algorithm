/*
 * 날짜: 2021-04-03
 * 분류: BFS
 * TIP: 불의 위치로부터 BFS, 각 칸에 언제 불이 도착하는지 먼저 계산
 * 이후 출발 위치로 BFS, 계산한 불 도착 시간보다 먼저 도착할 때만 이동이 가능하도록
 * if (dist[curX][curY] + 1 >= fireDist[nextX][nextY]) continue;
 */

#include <iostream>
#include <queue>

#define INF 1e9

#pragma warning (disable: 4996)

using namespace std;

int T, w, h;
char board[1002][1002] = {0};
int dist[1002][1002] = {0};
int fireDist[1002][1002] = {0};
queue<pair<int, int>> q;
queue<pair<int, int>> fireQ;
int moveX[4] = {1, -1, 0, 0};
int moveY[4] = {0, 0, 1, -1};

void init() {
    for (int i = 0; i < 1002; i++) {
        for (int j = 0; j < 1002; j++) {
            board[i][j] = 0;
            dist[i][j] = INF;
            fireDist[i][j] = INF;
        }
    }
    while(!q.empty())
        q.pop();
}

void bfs() {
    while (!q.empty()) {
        pair<int, int> p = q.front();
        int curX = p.first;
        int curY = p.second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nextX = curX + moveX[i];
            int nextY = curY + moveY[i];
            if (board[nextX][nextY] == 0) {
                cout << dist[curX][curY] + 1 << '\n';
                return;
            }
            if (dist[nextX][nextY] != INF || dist[curX][curY] + 1 >= fireDist[nextX][nextY] ||
                board[nextX][nextY] == '#')
                continue;
            dist[nextX][nextY] = dist[curX][curY] + 1;
            q.push({nextX, nextY});
        }
    }
    cout << "IMPOSSIBLE" << '\n';
}

void fireBfs() {
    while (!fireQ.empty()) {
        pair<int, int> p = fireQ.front();
        int curX = p.first;
        int curY = p.second;
        fireQ.pop();
        for (int i = 0; i < 4; i++) {
            int nextX = curX + moveX[i];
            int nextY = curY + moveY[i];
            if (fireDist[nextX][nextY] != INF || board[nextX][nextY] == 0 || board[nextX][nextY] == '*' ||
                board[nextX][nextY] == '#')
                continue;
            fireDist[nextX][nextY] = fireDist[curX][curY] + 1;
            fireQ.push({nextX, nextY});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while (T--) {
        init();
        cin >> w >> h;
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                cin >> board[i][j];
                if (board[i][j] == '@') {
                    q.push({i, j});
                    dist[i][j] = 0;
                } else if (board[i][j] == '*') {
                    fireQ.push({i, j});
                    fireDist[i][j] = 0;
                }
            }
        }
        fireBfs();
        bfs();
    }
    return 0;
}