/*
 * 날짜: 2021-04-03
 * 분류: Backtracking, Brute Force
 * TIP: 완전 탐색으로 사다리 가로의 모든 조합을 계산
 * 2차원 배열 Backtracking 이미 방문한 곳은 제외할 때
 * DFS 매개변수로 x, y를 나눠서 넘겨주기 보다 x*N+y와 같이 한 개로
 * 최소값을 구해야 하므로 완전 탐색 중 가능한 값이 나온다 하더라도 종료 X (최소값 계산)
 * 사다리 가로가 연속되면 안되므로 가로를 추가할 때 앞 뒤까지 체크 필요(주의!!)
 * 2차원 배열의 row, col 각각이 정의가 무엇인지 문제 읽고 확실하게 하기
 */

#include <iostream>
#define MAX 4

#pragma warning (disable: 4996)

using namespace std;

int N, M, H;
int result = MAX;
bool linePosition[32][12] = {false};

bool isCorrect() {
    for (int i = 1; i <= N; i++) {
        int curLine = i;
        for (int j = 1; j <= H; j++) {
            if (linePosition[j][curLine])
                curLine = curLine + 1;
            else if (linePosition[j][curLine - 1])
                curLine = curLine - 1;
        }
        if (curLine != i)
            return false;
    }
    return true;
}

void dfs(int cnt, int curPosition) {
    if (cnt > 3) {
        return;
    } else if (isCorrect()) {
        if (cnt < result)
            result = cnt;
    }
    for (int a = curPosition; a < H * (N - 1); a++) {
        int curHeight = a % H;
        int curLine = a / H;
        if (linePosition[curHeight + 1][curLine + 1] || linePosition[curHeight + 1][curLine] ||
            linePosition[curHeight + 1][curLine + 2])
            continue;
        linePosition[curHeight + 1][curLine + 1] = true;
        dfs(cnt + 1, (curLine * H) + curHeight + 1);
        linePosition[curHeight + 1][curLine + 1] = false;
    }
}


int main() {
    cin >> N >> M >> H;
    int h, n;
    for (int i = 0; i < M; i++) {
        cin >> h >> n;
        linePosition[h][n] = true;
    }
    dfs(0, 0);
    if (result == MAX)
        cout << "-1";
    else
        cout << result;
    return 0;
}