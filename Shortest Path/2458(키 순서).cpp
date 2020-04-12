/*
��¥: 2020-04-12
�з�: �÷��̵� �ͼ�
TIP: �÷��̵� �ͼ��� ����� to ����� �ִܰŸ��� ���ϰ�
��� ���� ����, A������  �� �� �ְų� A������ �� �� ������ true
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