/*
날짜: 2020-02-07
분류: DP
TIP: 다시 보기!
*/

#include <iostream>
#define MAX 1e9
#pragma warning (disable: 4996)

using namespace std;

int T, K;
int file_size[501] = { 0 };
int sum[501] = { 0 };
int dp[501][501] = { 0 };

int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		for (int j = 0; j < 501; j++) {
			file_size[j] = 0;
			for (int k = 0; k < 501; k++) {
				dp[j][k] = 0;
			}
		}

		scanf("%d", &K);
		for (int j = 1; j <= K; j++) {
			scanf("%d", &file_size[j]);
			//dp[j][j] = file_size[j];
			sum[j] = sum[j - 1] + file_size[j];
		}

		for (int j = 1; j < K ; j++) {
			for (int k = 1 + j; k <= K; k++) {
				dp[k - j][k] = MAX;
				for (int l = k - j; l < k; l++) {
					if (dp[k - j][k] > dp[k - j][l] + dp[l + 1][k] + sum[k] - sum[k - j - 1]) {
						dp[k - j][k] = dp[k - j][l] + dp[l + 1][k] + sum[k] - sum[k - j - 1];
					}
				}
			}
		}

		printf("%d\n", dp[1][K]);
	}
	return 0;
}