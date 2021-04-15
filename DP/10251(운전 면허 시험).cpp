/*
 * 날짜: 2021-04-16
 * 분류: DP
 * TIP: 상당히 많이 틀렸다..ㅠ
 * 최초 접근: dp[i][j][k][a] => k의 연료로 (i, j)에 a 방향을 바라볼 때 "소모 시간"
 * k: 0 ~ G, a: 현재 바라보는 방향(0또는 1)
 * 변의 개수는 의미 없고 꺽은 횟수만 카운트하면 소모 시간을 구할 수 있으므로
 * 개선된 접근: dp[i][j][k][a] => (i, j)까지 k번 꺽어서 a 방향을 바라볼 때 "최소 연료량"
 * k: 꺾는 횟수, a: 현재 바라보는 방향(0또는 1)
 */

#include <iostream>
#include <algorithm>
#include <cstring>

#define INF 1e9

#pragma warning (disable: 4996)

using namespace std;

int T, M, N, L, G;
int dist[102][102][2] = {0};
int dp[102][102][204][2] = {0};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while (T--) {
        int result = INF;
        memset(dp, 0x7f, sizeof dp);
        dp[0][0][0][0] = 0;
        dp[0][0][0][1] = 1;
        cin >> M >> N >> L >> G;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N - 1; j++) {
                cin >> dist[i][j][0];
            }
        }
        for (int i = 0; i < M - 1; i++) {
            for (int j = 0; j < N; j++) {
                cin >> dist[i][j][1];
            }
        }
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < M + N; k++) {
                    if (i + 1 < M) {
                        dp[i + 1][j][k][0] = min(dp[i + 1][j][k][0], dp[i][j][k][0] + dist[i][j][1]);
                        dp[i + 1][j][k + 1][0] = min(dp[i + 1][j][k + 1][0], dp[i][j][k][1] + dist[i][j][1]);
                    }

                    if (j + 1 < N) {
                        dp[i][j + 1][k][1] = min(dp[i][j + 1][k][1], dp[i][j][k][1] + dist[i][j][0]);
                        dp[i][j + 1][k + 1][1] = min(dp[i][j + 1][k + 1][1], dp[i][j][k][0] + dist[i][j][0]);
                    }
                }
            }
        }

        bool isPossible = false;
        for (int i = 0; i < M + N; i++) {
            for (int j = 0; j < 2; j++) {
                if (dp[M - 1][N - 1][i][j] <= G) {
                    result = (M + N - 2) * L + i;
                    isPossible = true;
                    break;
                }
            }
            if (isPossible)
                break;
        }
        if (isPossible)
            cout << result << '\n';
        else
            cout << "-1\n";
    }

    return 0;
}
