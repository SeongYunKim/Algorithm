/*
날짜: 2020-01-08
분류: BFS
TIP: BFS를 활용한 최단거리 구하기
*/

#include <iostream>
#include <queue>
#pragma warning (disable: 4996)

using namespace std;

int f, s, g, u, d;
int dist[1000001] = { 0 };
int visited[1000001] = { 0 };

void bfs();

int main() {
	scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);
	bfs();
	return 0;
}

void bfs() {
	queue<int> q;
	bool stair = true;
	q.push(s);
	dist[s] = 0;
	visited[s] = 1;
	while (!q.empty()) {
		int front = q.front();
		q.pop();

		if (front == g) {
			stair = false;
			break;
		}

		if (front + u <= f && visited[front + u] == 0) {
			q.push(front + u);
			dist[front + u] = dist[front] + 1;
			visited[front + u] = 1;
		}

		if (front - d >= 1 && visited[front - d] == 0) {
			q.push(front - d);
			dist[front - d] = dist[front] + 1;
			visited[front - d] = 1;
		}
	}

	if (!stair) {
		printf("%d", dist[g]);
	}
	else {
		printf("use the stairs");
	}
}