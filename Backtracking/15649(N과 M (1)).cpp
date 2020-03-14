#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#pragma warning (disable: 4996)

using namespace std;

int n, m;
int visited[10] = { 0 };
vector<int> v;
void backtracking(int cnt);

int main() {
	scanf("%d %d", &n, &m);
	backtracking(0);
	return 0;
}

void backtracking(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			printf("%d ", v[i]);
		}
		printf("\n");
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (visited[i] == 0) {
			visited[i] = 1;
			v.push_back(i);
			backtracking(cnt + 1);
			visited[i] = 0;
			v.pop_back();
		}
	}
}