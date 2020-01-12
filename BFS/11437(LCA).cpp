/*
날짜: 2020-01-12
분류: BFS(LCA)
TIP: Lowest Common Ancestor(최소 공통 조상)
BFS로 각 노드의 level(depth)계산 후
더 깊은 노드가 낮은 노드의 level까지 부모노드를 타고 올라간 후
두 노드 동시에 공통 조상이 나올때 까지 부모노드를 타고 올라간다
*/

#include <iostream>
#include <vector>
#include <queue>
#pragma warning (disable: 4996)

using namespace std;

int N, M;
vector<int> v[50001];
int tree[50001];
int level[50001];
int visited[50001] = { 0 };

int main() {
	queue<int> q;
	int q_id = 0;
	int node1, node2, front;
	scanf("%d", &N);
	for (int i = 1; i <= N - 1; i++) {
		scanf("%d %d", &node1, &node2);
		v[node1].push_back(node2);
		v[node2].push_back(node1);
	}
	visited[1] = 1;
	level[1] = 1;
	tree[1] = 1;
	for (int i = 0; i < v[1].size(); i++) {
		q.push(v[1][i]);
		visited[v[1][i]] = 1;
		level[v[1][i]] = level[1] + 1;
		tree[v[1][i]] = 1;
	}

	while (!q.empty()) {
		front = q.front();
		q.pop();
		for (int i = 0; i < v[front].size(); i++) {
			if (visited[v[front][i]] == 0) {
				q.push(v[front][i]);
				visited[v[front][i]] = 1;
				level[v[front][i]] = level[front] + 1;
				tree[v[front][i]] = front;
			}
		}
	}
	
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &node1, &node2);
		while (level[node1] != level[node2]) {
			if (level[node1] > level[node2]) {
				node1 = tree[node1];

			}
			else {
				node2 = tree[node2];
			}

		}
		while (node1 != node2) {
			node1 = tree[node1];
			node2 = tree[node2];
		}
		printf("%d\n", node1);
	}
	return 0;
}