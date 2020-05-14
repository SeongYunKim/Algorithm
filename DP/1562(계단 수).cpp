/*
날짜: 2020-05-14
분류: DP, Bitmasking
TIP: dp[i][j][k]: j로 끝나는 i자리 수 중 'k에 포함된 숫자'를 사용했던 정수의 수
k에 포함된 숫자: k를 2진수로 변환하였을 때 1인 각 자리
ex) k가 514? 1000000010 => 1, 9
OR( | ) 비트 연산을 통해 DP 연산 중 중복해서 사용한 숫자도 처리
*/

#include <iostream>
#define MOD 1000000000
#pragma warning (disable: 4996)

using namespace std;

long long dp[101][10][1024] = { 0 };
long long result = 0;
int temp[10] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= 9; i++) {
		dp[1][i][temp[i]] = 1;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = 0; k < 1024; k++) {
				if (j == 0) {
					dp[i][j][k | temp[j]] = (dp[i][j][k | temp[j]] + dp[i - 1][j + 1][k]) % MOD;
				}
				else if (j == 9) {
					dp[i][j][k | temp[j]] = (dp[i][j][k | temp[j]] + dp[i - 1][j - 1][k]) % MOD;
				}
				else {
					dp[i][j][k | temp[j]] = (dp[i][j][k | temp[j]] + dp[i - 1][j - 1][k]) % MOD;
					dp[i][j][k | temp[j]] = (dp[i][j][k | temp[j]] + dp[i - 1][j + 1][k]) % MOD;
				}
			}
		}
	}

	for (int i = 0; i <= 9; i++) {
		result = (result + dp[n][i][1023]) % MOD;
	}

	cout << result;
	return 0;
}