#include <iostream>
#include <vector>
#pragma warning (disable :4996)

using namespace std;

int N, M;
vector<int> v;

void backtracking(int cnt, int start);

int main() {
	scanf("%d %d", &N, &M);
	backtracking(0, 1);
	return 0;
}

void backtracking(int cnt, int start) {
	if (cnt == M) {
		for (int i = 0; i < v.size(); i++) {
			printf("%d ", v[i]);
		}
		printf("\n");
		return;
	}

	for (int i = start; i <= N; i++) {
		v.push_back(i);
		backtracking(cnt + 1, i + 1);
		v.pop_back();
	}
}