/*
날짜: 2020-04-06
분류: Greedy, Line Sweeping
TIP: from을 기준으로 오름차순 정렬 한 후, Greedy로
case1) 새로운 선이 기존 선과 겹치지 X
case2) 새로운 선이 기존 선과 일부 겹침
case3) 새로운 선이 기존 선에 포함
*/

#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning (disable: 4996)

using namespace std;

int n, rgt = -1000000001, result = 0;
vector<pair<int, int>> v;

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}

int main() {
	int start, end;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &start, &end);
		v.push_back({ start, end });
	}
	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); i++) {
		if (rgt <= v[i].first) {
			result += (v[i].second - v[i].first);
			rgt = v[i].second;
		}
		else if (rgt <= v[i].second) {
			result += (v[i].second - rgt);
			rgt = v[i].second;
		}
		else {

		}
	}

	printf("%d", result);
	return 0;
}