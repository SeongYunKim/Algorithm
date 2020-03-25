#include <iostream>
#include <vector>
#pragma warning (disable: 4996)

using namespace std;

int N, M;
vector<int> v;

void backtracking(int cnt);

int main() {
	scanf("%d %d", &N, &M);
	backtracking(0);
	return 0;
}

void backtracking(int cnt) {
	if (cnt == M) {
		for (int i = 0; i < v.size(); i++) {
			printf("%d ", v[i]);
		}
		printf("\n");
		return;
	}
	
	for (int i = 1; i <= N; i++) {
		v.push_back(i);
		backtracking(cnt + 1);
		v.pop_back();
	}
}
