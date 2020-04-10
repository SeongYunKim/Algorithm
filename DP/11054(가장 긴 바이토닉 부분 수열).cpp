/*
날짜: 2020-04-10
분류: DP
TIP:
dp[0][i]: i번째 수를 마지막으로 하는 증가하는 부분 수열의 최대 길이
dp[1][i]: i번째 수를 마지막으로 하는 (증가 후) 감소하는 부분 수열의 최대 길이
*/
#include <iostream>
#include <algorithm>
#pragma warning (disable: 4996)

using namespace std;

int n;
int arr[1001] = { 0 };
int dp[2][1002] = { 0 };

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		dp[0][i] = 1;
		dp[1][i] = 1;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				if (dp[0][i] < dp[0][j] + 1) {
					dp[0][i] = dp[0][j] + 1;
				}
			}
			else if (arr[i] < arr[j]) {
				int temp = max(dp[0][j], dp[1][j]) + 1;
				if (dp[1][i] < temp) {
					dp[1][i] = temp;
				}
			}
		}
	}

	int result = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < n; j++) {
			if (result < dp[i][j]) {
				result = dp[i][j];
			}
		}
	}
	

	printf("%d", result);
	return 0;
}