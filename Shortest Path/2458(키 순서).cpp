/*
날짜: 2020-04-12
분류: 플로이드 와샬
TIP: 플로이드 와샬로 모든점 to 모든점 최단거리를 구하고
모든 점에 대해, A점으로  갈 수 있거나 A점에서 갈 수 있으면 true
*/

#include <iostream>
#define INF 1e9
#pragma warning (disable: 4996)

using namespace std;

int n, m;
int from, to;
int dp[501][501] = { 0 };
int result = 0;

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)
				dp[i][j] = 0;
			else
				dp[i][j] = INF;
		}
	}

	for (int i = 0; i < m; i++) {
		scanf("%d %d", &from, &to);
		dp[from][to] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (dp[j][k] > dp[j][i] + dp[i][k]) {
					dp[j][k] = dp[j][i] + dp[i][k];
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		bool flag = true;
		for (int j = 1; j <= n; j++) {
			if (dp[i][j] == INF && dp[j][i] == INF) {
				flag = false;
				break;
			}
		}
		if (flag)
			result++;
	}

	printf("%d", result);
	return 0;
}