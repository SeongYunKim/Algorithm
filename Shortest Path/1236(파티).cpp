/*
날짜: 2020-01-13
분류: Dijkstra
TIP: Priority Queue를 활용한 Dijkstra 활용(to, from을 거꾸로)
*/

#include <iostream>
#include <queue>
#include <vector>
#define INF 1e9
#pragma warning (disable: 4996)

using namespace std;

int N, M, X;
int result[10001] = { 0 };
vector<pair<int, int>> v1[10001];
vector<pair<int, int>> v2[10001];

void dijkstra(vector<pair<int, int>> v[]);

int main() {
	int to, from, cost, max = -1;
	scanf("%d %d %d", &N, &M, &X);
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &from, &to, &cost);
		v1[from].push_back({ to, cost });
		v2[to].push_back({ from, cost });
	}
	dijkstra(v1);
	dijkstra(v2);
	for (int i = 1; i <= N; i++) {
		if (max < result[i]) {
			max = result[i];
		}
	}
	printf("%d", max);
	return 0;
}

void dijkstra(vector<pair<int, int>> v[]) {
	priority_queue<pair<int, int>> pq;
	int dist[10001];
	for (int i = 1; i <= N; i++) {
		dist[i] = INF;
	}

	pq.push({ 0, X });
	dist[X] = 0;
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		for (int i = 0; i < v[here].size(); i++) {
			int next = v[here][i].first;
			int nextCost = v[here][i].second;
			if (dist[next] > dist[here] + nextCost) {
				dist[next] = dist[here] + nextCost;
				pq.push({ -dist[next], next });
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		result[i] += dist[i];
	}
}