/*
��¥: 2020-01-11
�з�: DP
TIP: ���� ����� ���� �������� ���ϴ� ������ ���� ���� ������ ���� �ʿ�(Overflow ����)
*/

#include <iostream>
#define DIV 1000000000
#pragma warning (disable: 4996)

using namespace std;

int dp[201][201] = { 0 };
int N, K;

int main() {
	scanf("%d %d", &N, &K);
	for (int i = 0; i <= N; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= K; i++) {
		for (int j = 0; j <= N; j++) {
			for (int k = 0; k <= j; k++) {
				dp[i][j] += dp[i - 1][k];
				dp[i][j] %= DIV;
			}
		}
	}

	printf("%d", dp[K][N]);
	return 0;
}