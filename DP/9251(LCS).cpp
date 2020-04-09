/*
날짜: 2020-04-09
분류: DP, LCS(Longest Common Subsequence)
TIP: 행에서 현재까지 나온 문자열과 열에서 현재까지 나온 문자열 사이의 LCS 길이

길이가 아닌 Subsequence를 찾기 위해서는 DP 오른쪽 아래에서 부터
DP 배열의 값이 처음으로 바뀌는 각 행의 위치를 찾아야 함
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