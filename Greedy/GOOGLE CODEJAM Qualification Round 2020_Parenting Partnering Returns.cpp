/*
날짜: 2020-04-05
분류: Greedy
TIP: Activity 시작 시간 순으로 정렬한 후 Greedy로 순서대로 할당
정렬 없이 진행하면 예외 케이스 발생!
*/

#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning (disable: 4996)

using namespace std;

int t, n;
vector<pair<int, pair<int, int>>> v1;
vector<pair<int, char>> v2;
vector<int> schedule[2];
int end_time[2] = { -1, -1 };
bool is_possible = false;

bool cmp1(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b){
	return a.second.first < b.second.first;
}

bool cmp2(pair<int, char> a, pair<int, char> b) {
	return a.first < b.first;
}

int main() {
	scanf("%d", &t);
	for (int a = 1; a <= t; a++) {
		v1.clear();
		v2.clear();
		for (int i = 0; i < 2; i++) {
			schedule[i].clear();
			end_time[i] = -1;
		}
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			int start, end;
			scanf("%d %d", &start, &end);
			v1.push_back({ i, {start, end} });
		}

		sort(v1.begin(), v1.end(), cmp1);

		for (int i = 0; i < n; i++) {
			is_possible = false;
			for (int j = 0; j < 2; j++) {
				if (v1[i].second.first >= end_time[j]) {
					is_possible = true;
					schedule[j].push_back(v1[i].first);
					if (end_time[j] < v1[i].second.second) {
						end_time[j] = v1[i].second.second;
					}
					break;
				}
			}
			if (!is_possible) {
				break;
			}
		}

		printf("Case #%d: ", a);
		if (is_possible) {
			for (int i = 0; i < 2; i++) {
				for (int j = 0; j < schedule[i].size(); j++) {
					if (i == 0) {
						v2.push_back({ schedule[i][j], 'C' });
					}
					else {
						v2.push_back({ schedule[i][j], 'J' });
					}
				}
			}

			sort(v2.begin(), v2.end(), cmp2);

			for (int i = 0; i < n; i++) {
				printf("%c", v2[i].second);
			}
		}
		else {
			printf("IMPOSSIBLE");
		}
		printf("\n");
	}
}