/*
��¥: 2020-05-14
�з�: DP, Bitmasking
TIP: dp[i][j][k]: j�� ������ i�ڸ� �� �� 'k�� ���Ե� ����'�� ����ߴ� ������ ��
k�� ���Ե� ����: k�� 2������ ��ȯ�Ͽ��� �� 1�� �� �ڸ�
ex) k�� 514? 1000000010 => 1, 9
OR( | ) ��Ʈ ������ ���� DP ���� �� �ߺ��ؼ� ����� ���ڵ� ó��
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