/*
��¥: 2020-01-07
�з�: DP
TIP: ���� �տ� ���ϰų� ���Ӱ� �����ϰų� �ΰ��� ����� ��
*/

#include <iostream>
#pragma warning (disable: 4996)

using namespace std;

int N;
int num[100000] = { 0 };
int dp[100000] = { 0 };

int main() {
	int max = -1001;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf(" %d", &num[i]);
	}

	dp[0] = num[0];
	max = dp[0];
	for (int i = 1; i < N; i++) {
		if (dp[i - 1] + num[i] > num[i]) {
			dp[i] = dp[i - 1] + num[i];
		}
		else {
			dp[i] = num[i];
		}
		if (dp[i] > max) {
			max = dp[i];
		}
	}

	printf("%d", max);
	return 0;
}