#include <iostream>
#include <queue>
#pragma warning (disable: 4996)

using namespace std;

int N, M, V;
int line[1001][1001] = { 0 };
int bfs_visited[1001] = { 0 };
int dfs_visited[1001] = { 0 };

void bfs();
void dfs(int cur);

int main() {
	int to, from;
	scanf("%d %d %d", &N, &M, &V);
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &to, &from);
		line[to][from] = 1;
		line[from][to] = 1;
	}
	dfs_visited[V] = 1;
	dfs(V);
	printf("\n");
	bfs();
}

void bfs() {
	queue<int> q;
	bfs_visited[V] = 1;
	q.push(V);

	while (!q.empty()) {
		int cur;
		cur= q.front();
		printf("%d ", cur);
		q.pop();

		for (int i = 1; i <= N; i++) {
			if (line[cur][i] == 1) {
				if (bfs_visited[i] == 0) {
					q.push(i);
					bfs_visited[i] = 1;
				}
			}

		}
	}

}

void dfs(int cur) {
	printf("%d ", cur);
	//dfs_visited[cur] = 1;
	for (int i = 1; i <= N; i++) {
		if (line[cur][i] == 1) {
			if (dfs_visited[i] == 0) {
				dfs_visited[i] = 1;
				dfs(i);
			}
		}
	}
}