#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning (disable :4996)

using namespace std;

int N, M;
int arr[8] = { 0 };
vector<int> v;

void backtracking(int cnt, int start);

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	sort(arr, arr + N);

	backtracking(0, 0);
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

	for (int i = start; i < N; i++) {
		v.push_back(arr[i]);
		backtracking(cnt + 1, i + 1);
		v.pop_back();
	}
}