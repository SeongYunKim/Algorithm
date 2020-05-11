/*
��¥: 2020-05-11
�з�: BFS
TIP:
1. �� ������ ��ĥ �� �����Ƿ� �̵� �� �� ���� ��ġ�� ��ġ�Ѵٸ�,
�̵� �� �� ������ ��ġ�� ���� �� ������ �̵���Ŵ
2. ���� ���� ���� dist�迭�� ����ϸ� ���� ��￩ �Ķ� ������ �̵����� ��,
���� ������ �̵� Ƚ���� ������Ʈ�� �ȵ� => �̵� Ƚ���� ť�� �־� �Բ� ����
3. �Ķ� ������ Ż���ϸ� ���� ������ ������� �ش� �̵� ����(continue)
*/

#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#pragma warning (disable: 4996)

using namespace std;

int n, m, maxNM;
char board[12][12] = { 0 };
int visited[12][12][12][12] = { 0 };
int moveX[4] = { 1, -1, 0, 0 };
int moveY[4] = { 0, 0, 1, -1 };
int rX, rY, bX, bY;

void bfs();

int main() {
	string s;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	maxNM = max(n, m);
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			board[i][j] = s[j];
			if (board[i][j] == 'R') {
				rX = i;
				rY = j;
			}
			else if (board[i][j] == 'B') {
				bX = i;
				bY = j;
			}
		}
	}
	bfs();
	return 0;
}

void bfs() {
	int curRX, curRY, curBX, curBY, nextRX, nextRY, nextBX, nextBY, curDist;
	bool flagBlueOut = false;
	queue<pair<pair<int, int>, int>> q;
	q.push({ { rX * maxNM + rY, bX * maxNM + bY }, 0 });
	visited[rX][rY][bX][bY] = 1;
	while (!q.empty()) {
		pair<pair<int, int>, int> p = q.front();
		curRX = p.first.first / maxNM;
		curRY = p.first.first % maxNM;
		curBX = p.first.second / maxNM;
		curBY = p.first.second % maxNM;
		curDist = p.second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			flagBlueOut = false;
			int j = 0;
			while (true) {
				j++;
				nextBX = curBX + moveX[i] * j;
				nextBY = curBY + moveY[i] * j;
				if (board[nextBX][nextBY] != '#') {
					if (board[nextBX][nextBY] == 'O') {
						flagBlueOut = true;
						break;
					}
				}
				else
					break;
			}
			if (flagBlueOut)
				continue;

			nextBX = curBX + moveX[i] * (j - 1);
			nextBY = curBY + moveY[i] * (j - 1);

			j = 0;
			while (true) {
				j++;
				nextRX = curRX + moveX[i] * j;
				nextRY = curRY + moveY[i] * j;
				if (board[nextRX][nextRY] != '#') {
					if (board[nextRX][nextRY] == 'O') {
						cout << curDist + 1;
						exit(0);
					}
				}
				else
					break;
			}

			nextRX = curRX + moveX[i] * (j - 1);
			nextRY = curRY + moveY[i] * (j - 1);

			if (nextRX * maxNM + nextRY == nextBX * maxNM + nextBY) {
				switch (i) {
				case 0:
					if (curRX > curBX)
						nextBX--;
					else
						nextRX--;
					break;
				case 1:
					if (curRX > curBX)
						nextRX++;
					else
						nextBX++;
					break;
				case 2:
					if (curRY > curBY)
						nextBY--;
					else
						nextRY--;
					break;
				case 3:
					if (curRY > curBY)
						nextRY++;
					else
						nextBY++;
					break;

				}
			}
			if(visited[nextRX][nextRY][nextBX][nextBY] == 0) {
				visited[nextRX][nextRY][nextBX][nextBY] = 1;
				q.push({ { nextRX * maxNM + nextRY, nextBX * maxNM + nextBY }, curDist + 1 });
			}
		}
	}
	cout << "-1";
}