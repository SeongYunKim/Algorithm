/*
 * 날짜: 2021-04-03
 * 분류: DP
 * TIP: 배낭 문제
 * dp[i][j] = i번째 상품까지 j 비용이 있을 때 최대 메모리
 * j를 순회하며 최대 메모리가 M보다 큰 최소 j가 정답
 */

#include <iostream>

#pragma warning (disable: 4996)

using namespace std;

int N, M;
int m[101] = {0};
int c[101] = {0};
int dp[101][10001] = {0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        cin >> m[i];
    int maxCost = 0;
    for (int i = 1; i <= N; i++) {
        cin >> c[i];
        maxCost += c[i];
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= maxCost; j++) {
            if (j - c[i] >= 0)
                dp[i][j] = max(dp[i - 1][j - c[i]] + m[i], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    for (int i = 1; i <= maxCost; i++) {
        if (dp[N][i] >= M) {
            cout << i;
            return 0;
        }
    }

    return 0;
}