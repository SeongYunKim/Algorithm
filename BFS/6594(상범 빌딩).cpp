/*
날짜: 2020-04-10
분류: BFS
TIP: 3차원 공간에서의 BFS
*/

#include <iostream>
#include <queue>
#pragma warning (disable: 4996)

using namespace std;

int l, r, c, x;
char input;
int building[31][31][31] = { 0 };
int visited[31][31][31] = { 0 };
int dist[31][31][31] = { 0 };
int start[3] = { 0 };
int finish[3] = { 0 };
int move_x[6] = {1, -1, 0, 0, 0, 0};
int move_y[6] = {0, 0, 1, -1, 0, 0};
int move_z[6] = {0, 0, 0, 0, 1, -1};

void init();
int bfs(int start_x, int start_y, int start_z);

int main() {
	while (true) {
		scanf("%d %d %d", &l, &r, &c);
		if (l == 0 && r == 0 && c == 0)
			break;
		init();
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < r; j++) {
				for (int k = 0; k < c; k++) {
					scanf(" %c", &input);
					if (input == 'S') {
						start[0] = i;
						start[1] = j;
						start[2] = k;
						building[i][j][k] = 1;
					}
					else if (input == '#') {
						building[i][j][k] = 0;
					}
					else if (input == '.') {
						building[i][j][k] = 1;
					}
					else if (input == 'E') {
						finish[0] = i;
						finish[1] = j;
						finish[2] = k;
						building[i][j][k] = 2;
					}
				}
			}
		}

		x = bfs(start[0], start[1], start[2]);
		if (x == -1)
			printf("Trapped!\n");
		else
			printf("Escaped in %d minute(s).\n", x);
	}
	return 0;
}

int bfs(int start_x, int start_y, int start_z) {
	queue<pair<int, pair<int, int>>> q;
	pair<int, pair<int, int>> p;
	bool flag = false;
	q.push({ start_x, {start_y, start_z} });
	visited[start_x][start_y][start_z] = { 0 };
	while (!q.empty()) {
		p = q.front();
		q.pop();
		int cur_x = p.first;
		int cur_y = p.second.first;
		int cur_z = p.second.second;
		for (int i = 0; i < 6; i++) {
			int next_x = cur_x + move_x[i];
			int next_y = cur_y + move_y[i];
			int next_z = cur_z + move_z[i];
			if (next_x < 0 || next_x >= l || next_y < 0 || next_y >= r || next_z < 0 || next_z >= c)
				continue;
			if (visited[next_x][next_y][next_z] == 0 && building[next_x][next_y][next_z] > 0) {
				//printf("(%d, %d, %d)\n", next_x, next_y, next_z);
				visited[next_x][next_y][next_z] = 1;
				q.push({ next_x, {next_y, next_z} });
				dist[next_x][next_y][next_z] = dist[cur_x][cur_y][cur_z] + 1;
				if (building[next_x][next_y][next_z] == 2) {
					flag = true;
					break;
				}
			}
		}
		if (flag)
			break;
	}
	if (flag)
		return dist[finish[0]][finish[1]][finish[2]];
	else
		return -1;
}

void init() {
	x = 0;
	for (int i = 0; i < 31; i++) {
		for (int j = 0; j < 31; j++) {
			for (int k = 0; k < 31; k++) {
				building[i][j][k] = 0;
				visited[i][j][k] = 0;
				dist[i][j][k] = 0;
			}
		}
	}
}