/*
��¥: 2020-04-09
�з�: DP, LCS(Longest Common Subsequence)
TIP: �࿡�� ������� ���� ���ڿ��� ������ ������� ���� ���ڿ� ������ LCS ����

���̰� �ƴ� Subsequence�� ã�� ���ؼ��� DP ������ �Ʒ����� ����
DP �迭�� ���� ó������ �ٲ�� �� ���� ��ġ�� ã�ƾ� ��
*/

#include <iostream>
#include <algorithm>
#include <string>
#pragma warning (disable: 4996)

using namespace std;

string s1, s2;
int dp[1001][1001] = { 0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> s1;
	cin >> s2;
	for (int i = 0; i < s1.length(); i++) {
		for (int j = 0; j < s2.length(); j++) {
			if (s1[i] == s2[j]) {
				dp[i + 1][j + 1] = dp[i][j] + 1;
			}
			else {
				dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
			}
		}
	}

	int result_max = dp[s1.length()][s2.length()];
	cout << result_max;
	return 0;
}