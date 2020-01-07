/*
��¥: 2020-01-07
�з�: DP
TIP: ���� �տ� ���ϰų� ���Ӱ� �����ϰų� �ΰ��� ����� ��
     +) ���� ������ ���, ���� �տ� ���ϰų� �ش� ���� �����ϰų� �ΰ��� ����� ��
*/

#include <iostream>
#pragma warning (disable: 4996)

using namespace std;

int N;
int num[100000] = { 0 };
int dp[100000][2] = { 0 };

int main() {
	int max = -1001;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf(" %d", &num[i]);
	}

	dp[0][0] = num[0];
	dp[0][1] = 0;
	max = dp[0][0];

	for (int i = 1; i < N; i++) {
		if (dp[i - 1][0] + num[i] > num[i]) {
			dp[i][0] = dp[i - 1][0] + num[i];
		}
		else {
			dp[i][0] = num[i];
		}
		if (dp[i - 1][0] > dp[i - 1][1] + num[i]) {
			dp[i][1] = dp[i - 1][0];
		}
		else {
			dp[i][1] = dp[i - 1][1] + num[i];
		}

		if (dp[i][0] > dp[i][1]) {
			if (max < dp[i][0])
				max = dp[i][0];
		}
		else {
			if (max < dp[i][1])
				max = dp[i][1];
		}
	}

	printf("%d", max);
	return 0;
}