#include <iostream>
#pragma warning (disable: 4996)

using namespace std;

int N,  result = 0;
int visited[3000][3000] = { 0 };
int move_x[6] = { 23, -23, 1, 1, -1, -1 };
int move_y[6] = { 0, 0, 1, -1, 1, -1 };
int match[6][2] = { {2, 4}, {3, 5}, {0, 3}, {1, 2}, {0, 5}, {1, 4} };

void dfs(int cnt, int cur_x, int cur_y, int cur_dir);

int main() {
	scanf("%d", &N);
	visited[477][500] = 1;
	dfs(0, 500, 500, 0);
	printf("%d", result);
	return 0;
}

void dfs(int cnt, int cur_x, int cur_y, int cur_dir) {
	printf("%d: %d %d %d\n", cnt, cur_x, cur_y, cur_dir);
	if (cnt == N) {
		if (cur_x == 477 && cur_y == 500) {
			printf("adflakjs;\n");
		}
		printf("\n");
		if (visited[cur_x][cur_y] > 1) {
			result++;
		}
		return;
	}
	int next_x, next_y;
	for (int i = 0; i < 2; i++) {
		next_x = cur_x + move_x[match[cur_dir][i]];
		next_y = cur_y + move_y[match[cur_dir][i]];
		visited[next_x][next_y]++;
		dfs(cnt + 1, next_x, next_y, match[cur_dir][i]);
		visited[next_x][next_y]--;
	}
}