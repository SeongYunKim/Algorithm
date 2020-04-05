/*
��¥: 2020-04-06
�з�: Greedy, Line Sweeping
TIP: from�� �������� �������� ���� �� ��, Greedy��
case1) ���ο� ���� ���� ���� ��ġ�� X
case2) ���ο� ���� ���� ���� �Ϻ� ��ħ
case3) ���ο� ���� ���� ���� ����
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