/*
날짜: 2020-04-14
분류: DP
TIP: x <= i < y
dp[x][y] = min(dp[x][i] + dp[i][y] + x번째 행렬 행수 * x번째 행렬 열수 * y번째 행렬 열수)
*/

#include <iostream>
#define INF 1e9
#pragma warning (disable: 4996)

using namespace std;

int n;
int r, c;
int arr[501][2] = { 0 };
int dp[501][501] = { 0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> r >> c;
		arr[i][0] = r;
		arr[i][1] = c;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n - i; j++) {
			int min = INF;
			for (int k = j; k <= j + i - 1; k++) {
				int multiple_num = dp[j][k] + dp[k + 1][j + i] + arr[j][0] * arr[j + i][1] * arr[k][1];
				if (min > multiple_num) {
					min = multiple_num;
				}
			}
			dp[j][j + i] = min;
		}
	}
	
	cout << dp[1][n];
	return 0;
}