/*
날짜: 2020-04-13
분류: BFS, 위상정렬
TIP: 위상 정렬 - Directed Acyclic Graph에서 edge의 방향을 거스리지 않도록 node를 정렬
1. queue에 진입차수가 0인 node 삽입
2. queue에서 front를 pop해 연결된 모든 edge 제거
3. edge 제거 후 진입차수가 0인 된 node를 queue에 삽입
4. queue가 빌 때 까지 2~3 반복
모든 원소 방문하기 전에 queue가 빈다면 Acyclic Graph가 아님!
*/

#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
#pragma warning (disable: 4996)

using namespace std;

int n, m;
int before, after;
vector<int> v[1001];

void solution1_by_bfs();
void solution2_by_topology_sort();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solution2_by_topology_sort();
	return 0;
}

void solution1_by_bfs() {
	int visited[1001] = { 0 };
	int dist[1001] = { 0 };
	for (int i = 0; i < 1001; i++) {
		dist[i] = -1;
	}
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> before >> after;
		v[before].push_back(after);
	}

	for (int i = 1; i <= n; i++) {
		if (visited[i] == 0) {
			queue<int> q;
			q.push(i);
			dist[i] = 0;
			visited[i] = 1;
			while (!q.empty()) {
				int cur = q.front();
				q.pop();
				for (int j = 0; j < v[cur].size(); j++) {
					int next = v[cur][j];
					visited[next] = 1;
					if (dist[next] < dist[cur] + 1) {
						dist[next] = dist[cur] + 1;
						q.push(next);
					}
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << dist[i] + 1 << " ";
	}
}

void solution2_by_topology_sort() {
	int in_degree[1001] = { 0 };
	int dist[1001] = { 0 };
	for (int i = 0; i < 1001; i++) {
		dist[i] = INF;
	}
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> before >> after;
		v[before].push_back(after);
		in_degree[after]++;
	}

	queue<int> q;

	for (int i = 1; i <= n; i++) {
		if (in_degree[i] == 0) {
			dist[i] = 0;
			q.push(i);
		}
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i];
			in_degree[next]--;
			if (in_degree[next] == 0) {
				q.push(next);
				dist[next] = dist[cur] + 1;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << dist[i] + 1 << " ";
	}
}