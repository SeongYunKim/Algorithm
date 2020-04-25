/*
��¥: 2020-04-25
�з�: DP, DFS
TIP: �ѹ� DFS�� ������ ĭ�� �ִ븦 ã�� ���̹Ƿ� �� �̻� ���� X
DFS �������� �̹� �ִ��� ĭ�� ������ ��, ��� ȣ�� �ߴ�
*/

#include <iostream>
#pragma warning (disable: 4996)

using namespace std;

int n, result = 1;
int arr[501][501] = { 0 };
int dp[501][501] = { 0 };
int moveX[4] = { 1, -1, 0, 0 };
int moveY[4] = { 0, 0, 1, -1 };


int dfs(int x, int y);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			dp[i][j] = 0;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dp[i][j] = dfs(i, j);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			//cout << dp[i][j] << " ";
			if (result < dp[i][j])
				result = dp[i][j];
		}
		//cout << endl;
	}
	cout << result;
	return 0;
}

int dfs(int x, int y) {
	if (dp[x][y] != 0) 
		return dp[x][y];
	dp[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int nextX = x + moveX[i];
		int nextY = y + moveY[i];
		if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= n)
			continue;
		if (arr[x][y] < arr[nextX][nextY]) {
			int temp = dfs(nextX, nextY) + 1;
			if (dp[x][y] < temp)
				dp[x][y] = temp;
		}
	}
	return dp[x][y];
}

