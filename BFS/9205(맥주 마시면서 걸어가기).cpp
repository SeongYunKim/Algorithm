/*
날짜: 2020-01-18
분류: BFS
TIP: 전역변수를 사용하여 for문 돌 때 초기화를 잘하자(특히 vector, array)
*/

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#pragma warning (disable: 4996)

using namespace std;

int t, n;
int start_x, start_y;
int end_x, end_y;
int visited[101] = { 0 };
vector<pair<int, int>> v;


bool bfs();

int main() {
	bool result;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		v.clear();
		for (int j = 0; j < 101; j++) {
			visited[j] = 0;
		}
		result = false;
		scanf("%d", &n);
		scanf("%d %d", &start_x, &start_y);
		for (int j = 0; j < n; j++) {
			int x, y;
			scanf("%d %d", &x, &y);
			v.push_back({ x, y });
		}
		scanf("%d %d", &end_x, &end_y);
		v.push_back({ end_x, end_y });
		result = bfs();
		if (result) {
			printf("happy\n");
		}
		else {
			printf("sad\n");
		}
	}

	return 0;
}

bool bfs() {
	queue<pair<int, int>> q;
	bool result = false;
	q.push({ start_x,  start_y });
	while (!q.empty()) {
		int front_x, front_y;
		front_x = q.front().first;
		front_y = q.front().second;
		q.pop();
		for (int i = 0; i < v.size(); i++) {
			int distance = abs(front_x - v[i].first) + abs(front_y - v[i].second);
			if (distance <= 50 * 20 && visited[i] == 0) {
				q.push({ v[i].first, v[i].second });
				visited[i] = 1;
				if (i == v.size() - 1) {
					result = true;
					break;
				}
			}
		}
		if (result) {
			break;
		}
	}

	return result;
}