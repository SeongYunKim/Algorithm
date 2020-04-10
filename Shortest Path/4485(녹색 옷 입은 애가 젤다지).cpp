/*
날짜: 2020-04-11
분류: 최단거리, 다익스트라
TIP: 2차원 공간에서의 다익스트라를 활용한 최단거리 구하기
*/

#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
#pragma warning (disable: 4996)

using namespace std;

int n, problem_num = 1;
int arr[126][126] = { 0 };
int dist[126][126] = { 0 };
int x_move[4] = { 1, -1, 0 ,0 };
int y_move[4] = { 0, 0, 1 ,-1 };
priority_queue<pair<int, pair<int, int>>> pq;

void init();

int main() {
	while (true) {
		scanf("%d", &n);
		if (n == 0)
			break;
		init();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &arr[i][j]);
			}
		}
		pq.push({ -arr[0][0], {0, 0} });
		dist[0][0] = arr[0][0];
		while (!pq.empty()) {
			pair<int, pair<int, int>> p;
			p = pq.top();
			pq.pop();
			int cur_dist = -p.first;
			int cur_x = p.second.first;
			int cur_y = p.second.second;
			if (cur_x == n - 1 && cur_y == n - 1) {
				printf("Problem %d: ", problem_num++);
				printf("%d\n", cur_dist);
				break;
			}
			for (int i = 0; i < 4; i++) {
				int next_x = cur_x + x_move[i];
				int next_y = cur_y + y_move[i];
				if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= n)
					continue;
				if (dist[next_x][next_y] > cur_dist + arr[next_x][next_y]) {
					dist[next_x][next_y] = cur_dist + arr[next_x][next_y];
					pq.push({ -dist[next_x][next_y], {next_x, next_y} });
				}
			}
		}
	}
}


void init() {
	for (int i = 0; i < 126; i++) {
		for (int j = 0; j < 126; j++) {
			arr[i][j] = 0;
			dist[i][j] = INF;
			while (!pq.empty()) {
				pq.pop();
			}
		}
	}
}