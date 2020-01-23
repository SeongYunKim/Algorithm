/*
날짜: 2020-01-23
분류: Dijkstra
*/

#include <iostream>
#include <queue>
#include <vector>
#define INF 1e9
#pragma warning (disable: 4996)

using namespace std;

int N, M;
vector<pair<int, int>> v[1001];
long long int dist[1001] = { 0 };

int main() {
	int from, to, cost, start, end;
	scanf("%d", &N);
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &from, &to, &cost);
		v[from].push_back({ to, cost });
	}
	scanf("%d %d", &start, &end);

	for (int i = 1; i <= N; i++) {
		dist[i] = INF;
	}

	priority_queue<pair<long long int, int>> pq;
	dist[start] = 0;
	pq.push({ 0, start });
	while (!pq.empty()) {
		int here_cost = - pq.top().first;
		int here = pq.top().second;
		pq.pop();

		for (int i = 0; i < v[here].size(); i++) {
			int next = v[here][i].first;
			int next_cost = v[here][i].second;
			if (dist[here] + next_cost < dist[next]) {
				dist[next] = dist[here] + next_cost;
				pq.push({ -dist[next], next });
			}
		}
	}
	printf("%d", dist[end]);
}