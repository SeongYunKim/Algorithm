/*
날짜: 2020-04-02
분류: 최단 경로(벨만 포드)
TIP: 벨만 포드 알고리즘 시간복잡도 O(VE)
모든 엣지에 대해 Edge Relaxation을 전체 노드수만큼 반복
V번 반복 후 한번 더 반복 시 최단경로가 바뀐다? ==> Negative Cycle
*/

#include <iostream>
#include <vector>
#define INF 1e9
#pragma warning (disable: 4996)

using namespace std;

int tc, n, m, w;
int from, to, cost;
int adj[501][501] = { 0 };
int dist[501] = { 0 };
bool cycle = false;

int main() {
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++) {
		for (int i = 0; i < 501; i++) {
			for (int j = 0; j < 501; j++) {
				adj[i][j] = INF;
			}
			dist[i] = INF;
			cycle = false;
		}

		scanf("%d %d %d", &n, &m, &w);
		for (int j = 0; j < m; j++) {
			scanf("%d %d %d", &from, &to, &cost);
			if (cost < adj[from][to]) {
				adj[from][to] = cost;
				adj[to][from] = cost;
			}
		}

		for (int j = 0; j < w; j++) {
			scanf("%d %d %d", &from, &to, &cost);
			adj[from][to] = -cost;
		}

		dist[1] = 0;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				for (int k = 1; k <= n; k++) {
					if (adj[j][k] != INF) {
						if (dist[j] + adj[j][k] < dist[k])
							dist[k] = dist[j] + adj[j][k];
					}
				}
			}
		}

		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (adj[j][k] != INF) {
					if (dist[j] + adj[j][k] < dist[k])
						cycle = true;
				}
			}
		}

		if (cycle)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}