/*
날짜: 2020-01-27
분류: DFS
TIP: DFS를 시작과 끝을 바꿔가며 진행하여 전후관계 파악
*/


#include <iostream>
#include <vector>
#pragma warning (disable: 4996)

using namespace std;

int n, k, s;
vector<int> v[401];
int visited[401] = { 0 };
bool reach = false;
bool know = false;

void dfs(int from, int to);

int main() {
	int to, from;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < k; i++) {
		scanf("%d %d", &from, &to);
		v[from].push_back(to);
	}
	scanf("%d", &s);
	for (int i = 0; i < s; i++) {
		scanf("%d %d", &from, &to);
		for (int i = 0; i < 401; i++)
			visited[i] = 0;
		reach = false;
		know = false;
		dfs(from, to);
		if (reach) {
			printf("-1\n");
			know = true;
		}
		for (int i = 0; i < 401; i++)
			visited[i] = 0;
		reach = false;
		dfs(to, from);
		if (reach) {
			printf("1\n");
			know = true;
		}
		if (!know) {
			printf("0\n");
		}
	}
}

void dfs(int from, int to) {

	for (int i = 0; i < v[from].size(); i++) {
		int next = v[from][i];
		if (visited[next] == 0) {
			if (next == to) {
				reach = true;
				return;
			}
			visited[next] = 1;
			dfs(next, to);
			//visited[next] = 10;
		}
	}
}