/*
날짜: 2020-04-07
분류: DP, LIS(Longest Increasing Subsequence)
TIP: DP를 이용한 LIS 시간복잡도 = O(N^2)
*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#pragma warning (disable: 4996)

using namespace std;

int n;
vector<pair<int, int>> v1;
int dp[100000] = { 0 };

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}

int main() {
	int start, end;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &start, &end);
		v1.push_back({ start, end });
		dp[i] = 1;
	}

	sort(v1.begin(), v1.end(), cmp);

	int max = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (v1[i].second > v1[j].second) {
				if (dp[i] < dp[j] + 1) {
					dp[i] = dp[j] + 1;
					if (dp[i] > max) {
						max = dp[i];
					}
				}
			}
		}
	}

	printf("%d\n", n - max);
	return 0;
}