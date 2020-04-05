/*
날짜: 2020-04-05
분류: Backtracking
TIP: N이 10 이하인 경우는 Backtracking 완전탐색으로 가능
그러나 N이 1000 이하인 경우 시간 초과 발생하여 Greedy로 Solve
*/

#include <iostream>
#include <vector>
#pragma warning (disable: 4996)

using namespace std;

int t, n;
int time_arr[1001][2] = { 0 };
vector<pair<int, int>> schedule[2];
vector<int> v1;
bool is_complete = false;

bool check(int i, int j) {
	for (int k = 0; k < schedule[j].size(); k++) {
		if (time_arr[i][1] <= schedule[j][k].first || time_arr[i][0] >= schedule[j][k].second) {

		}
		else {
			return false;
		}
	}
	return true;
}

void backtracking(int cnt) {
	if (is_complete)
		return;
	if (cnt == n) {
		is_complete = true;
		for (int i = 0; i < n; i++) {
			if (v1[i] == 0)
				printf("C");
			else
				printf("J");
			//printf("%d", v[i]);
		}
		return;
	}

	bool is_possible = false;
	for (int j = 0; j < 2; j++) {
		if (check(cnt, j)) {
			is_possible = true;
			schedule[j].push_back({ time_arr[cnt][0], time_arr[cnt][1] });
			v1.push_back(j);
			backtracking(cnt + 1);
			v1.pop_back();
			schedule[j].pop_back();
		}
	}
}

int main() {
	scanf("%d", &t);
	for (int a = 1; a <= t; a++) {
		schedule[0].clear();
		schedule[1].clear();
		v1.clear();
		is_complete = false;
		scanf("%d", &n);
		printf("Case #%d: ", a);
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &time_arr[i][0], &time_arr[i][1]);
		}

		schedule[0].push_back({ time_arr[0][0], time_arr[0][1] });
		v1.push_back(0);
		backtracking(1);

		if (!is_complete) {
			printf("IMPOSSIBLE");
		}
		printf("\n");
	}
}