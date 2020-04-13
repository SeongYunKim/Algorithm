/*
��¥: 2020-04-13
�з�: BFS, ��������
TIP: ���� ���� - Directed Acyclic Graph���� edge�� ������ �Ž����� �ʵ��� node�� ����
1. queue�� ���������� 0�� node ����
2. queue���� front�� pop�� ����� ��� edge ����
3. edge ���� �� ���������� 0�� �� node�� queue�� ����
4. queue�� �� �� ���� 2~3 �ݺ�
��� ���� �湮�ϱ� ���� queue�� ��ٸ� Acyclic Graph�� �ƴ�!
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