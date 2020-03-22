/*
날짜: 2020-01-22
분류: BFS, DFS
TIP: 테스트 케이스가 여러개일 경우 초기화를 잘 하자!
	 그래프가 연결 그래프라는 보장이 없으므로 모든 노드에서부터 탐색하며 체크해야
*/

#include <iostream>
#include <vector>
#include <queue>
#pragma warning (disable: 4996)

using namespace std;

int k, v, e;
int visited[20001] = { 0 };
int team[20001] = { 0 };
bool result = true;
vector<int> vec[20001];

void bfs(int start);

int main() {
	int to, from;
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		result = true;
		for (int j = 0; j < 20001; j++) {
			visited[j] = 0;
			team[j] = 0;
			vec[j].clear();
		}
		scanf("%d %d", &v, &e);
		for (int j = 0; j < e; j++) {
			scanf("%d %d", &to, &from);
			vec[to].push_back(from);
			vec[from].push_back(to);
		}

		for (int j = 1; j <= v; j++) {
			bfs(j);
		}

		if (result) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
	return 0;
}

void bfs(int start) {
	queue<int> q;
	if (visited[start] == 0) {
		q.push(start);
		team[start] = 0;
		visited[start] = 1;
		while (!q.empty()) {
			int front = q.front();
			q.pop();
			for (int i = 0; i < vec[front].size(); i++) {
				int next = vec[front][i];
				if (visited[next] == 0) {
					visited[next] = 1;
					team[next] = (team[front] + 1) % 2;
					q.push(next);
				}
				else {
					if (team[next] != (team[front] + 1) % 2) {
						result = false;
						break;
					}
				}
			}
			if (!result) {
				break;
			}
		}
	}
}