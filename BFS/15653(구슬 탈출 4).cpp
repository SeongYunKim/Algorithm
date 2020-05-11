/*
날짜: 2020-05-11
분류: BFS
TIP:
1. 두 구슬이 겹칠 수 없으므로 이동 후 두 구슬 위치가 일치한다면,
이동 전 두 구슬의 위치를 보고 한 구슬을 이동시킴
2. 빨강 구슬 기준 dist배열을 사용하면 판을 기울여 파랑 구슬만 이동했을 때,
빨강 구슬의 이동 횟수가 업데이트가 안됨 => 이동 횟수를 큐에 넣어 함께 관리
3. 파랑 구슬이 탈출하면 빨강 구슬과 상관없이 해당 이동 무시(continue)
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