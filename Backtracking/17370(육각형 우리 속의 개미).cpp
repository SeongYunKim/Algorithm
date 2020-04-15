/*
날짜: 2020-04-16
분류: Backtracking
TIP: 이미 방문했던 점을 또 방문할 때 cnt가 N-1이면 result에 1 추가
TIP: */

#include <iostream>
#pragma warning (disable: 4996)

using namespace std;

int N, result = 0;
int visited[3000][3000] = { 0 };
int move_x[6] = { 0, 0, 1, 1, -1, -1 };
int move_y[6] = { 23, -23, 1, -1, 1, -1 };
int match[6][2] = { {2, 4}, {3, 5}, {0, 3}, {1, 2}, {0, 5}, {1, 4} };

void dfs(int cnt, int cur_x, int cur_y, int cur_dir);

int main() {
	scanf("%d", &N);
	visited[500][477] = 1;
	visited[500][500] = 1;
	dfs(0, 500, 500, 0);
	printf("%d", result);
	return 0;
}

void dfs(int cnt, int cur_x, int cur_y, int cur_dir) {
	if (cnt == N) {
		return;
	}

	int next_x, next_y;
	for (int i = 0; i < 2; i++) {
		next_x = cur_x + move_x[match[cur_dir][i]];
		next_y = cur_y + move_y[match[cur_dir][i]];
		if (visited[next_x][next_y] == 0) {
			visited[next_x][next_y]++;
			dfs(cnt + 1, next_x, next_y, match[cur_dir][i]);
			visited[next_x][next_y]--;
		}
		else {
			if (cnt == N - 1)
				result++;
		}
	}
}