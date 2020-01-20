/*
날짜: 2020-01-21
분류: BFS
TIP: 불이 하나도 없는 경우 예외처리 필요
*/

#include <iostream>
#include <queue>
#define MAX 1e9
#pragma warning (disable: 4996)

using namespace std;

int R, C;
int start_x, start_y;
queue<pair<int, int>> q;
char maze[1001][1001] = { 0 };
int dist[1001][1001] = { 0 };
int visited[1001][1001] = { 0 };
int fire[1001][1001] = { 0 };
int fire_visited[1001][1001] = { 0 };
int x_move[4] = { -1, 1, 0, 0 };
int y_move[4] = { 0, 0, -1, 1 };

int main() {
	scanf("%d %d", &R, &C);
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			fire[i][j] = MAX;
			scanf(" %c", &maze[i][j]);
			if (maze[i][j] == 'J') {
				start_x = i;
				start_y = j;
			}

			if (maze[i][j] == 'F') {
				fire[i][j] = 0;
				q.push({ i, j });
				fire_visited[i][j] = 1;
			}
		}
	}

	while (!q.empty()) {
		int front_x, front_y;
		front_x = q.front().first;
		front_y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_x = front_x + x_move[i];
			int next_y = front_y + y_move[i];
			if (next_x < 0 || next_y < 0 || next_x >= R || next_y >= C) {
				continue;
			}
			if (fire_visited[next_x][next_y] == 0 && maze[next_x][next_y] != '#') {
				fire[next_x][next_y] = fire[front_x][front_y] + 1;
				fire_visited[next_x][next_y] = 1;
				q.push({ next_x, next_y });
			}
		}
	}

	/*
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			printf("%d ", fire[i][j]);
		}
		printf("\n");
	}
	*/
	

	bool finish = false;
	q.push({ start_x, start_y });
	visited[start_x][start_y] = 1;
	while (!q.empty()) {
		int front_x, front_y;
		front_x = q.front().first;
		front_y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_x = front_x + x_move[i];
			int next_y = front_y + y_move[i];
			if (next_x < 0 || next_y < 0 || next_x >= R || next_y >= C) {
				printf("%d", dist[front_x][front_y] + 1);
				finish = true;
				break;
			}
			if (visited[next_x][next_y] == 0 && maze[next_x][next_y] != '#' && dist[front_x][front_y] + 1 < fire[next_x][next_y]) {
				dist[next_x][next_y] = dist[front_x][front_y] + 1;
				visited[next_x][next_y] = 1;
				q.push({ next_x, next_y });
			}
		}
		if (finish) {
			break;
		}
	}

	if (!finish) {
		printf("IMPOSSIBLE");
	}
	return 0;
}