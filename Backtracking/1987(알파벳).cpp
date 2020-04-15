/*
날짜: 2020-01-06
분류: DFS
TIP: visited 배열을 사용하지 않는 DFS
*/

#include <iostream>
#pragma warning (disable: 4996)

using namespace std;

int R, C;
char board[22][22] = { 0 };
//int visited[22][22] = { 0 };
int check[200] = { 0 };
int move_x[4] = { 0, 0, 1, -1 };
int move_y[4] = { 1, -1, 0, 0 };
int max_depth = 1;

void dfs(int x, int y, int depth);

int main() {
	scanf("%d %d", &R, &C);
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			scanf(" %c", &board[i][j]);
		}
	}
	check[board[1][1]] = 1;
	dfs(1, 1, max_depth);
	printf("%d", max_depth);
	return 0;
}

void dfs(int x, int y, int depth) {
	//visited[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int next_x = x + move_x[i];
		int next_y = y + move_y[i];
		if (next_x < 1 || next_y < 1 || next_x > R || next_y > C)
			continue;
		//if (visited[next_x][next_y] == 0 && check[board[next_x][next_y]] == 0) {
		if (check[board[next_x][next_y]] == 0) {
			check[board[next_x][next_y]] = 1;
			if (max_depth < depth + 1) {
				max_depth = depth + 1;
			}
			dfs(next_x, next_y, depth + 1);
			check[board[next_x][next_y]] = 0;
		}
	}
}