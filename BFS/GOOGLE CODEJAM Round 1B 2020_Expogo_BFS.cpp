/*
날짜: 2020-04-21
분류: BFS
TIP: BFS로 두번째 테스트 케이스까지 시간초과 없이 가능
각 노드를 오기위해 이동한 방향을 맵에 저장하여 이동 경로 추적
*/

#include <iostream>
#include <queue>
#include <map>
#include <cmath>
#include <vector>
#pragma warning (disable: 4996)

using namespace std;

typedef struct item{
	int x;
	int y;
	int cnt;
}item;

int t;
int x, y;
int x_move[4] = { 0, 0, 1, -1 };
int y_move[4] = { 1, -1, 0 , 0 };
vector<int> result;
map<pair<pair<int, int>, int>, int> m;

void bfs();

void init() {
	m.clear();
	result.clear();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	for (int a = 1; a <= t; a++) {
		init();
		cin >> x >> y;
		cout << "Case #" << a << ": ";
		if ((x + y) % 2) {
			bfs();
		}
		else {
			cout << "IMPOSSIBLE";
		}
		cout << "\n";
	}
	return 0;
}

void bfs() {
	queue <item> q;
	q.push({ 0, 0, 0 });
	m[{{0, 0}, 0}] = -1;
	
	while (!q.empty()) {
		int cur_cnt = q.front().cnt;
		int cur_x = q.front().x;
		int cur_y = q.front().y;
		q.pop();

		if (cur_cnt == 9) {
			cout << "IMPOSSIBLE";
			break;
		}
		
		if (cur_x == x && cur_y == y) {
			int temp_x = cur_x, temp_y = cur_y, temp_cnt = cur_cnt;
			while (m[{{temp_x, temp_y}, temp_cnt}] != -1) {
				int dir = m[{{temp_x, temp_y}, temp_cnt}];
				temp_x = temp_x - x_move[dir] * pow(2, temp_cnt - 1);
				temp_y = temp_y - y_move[dir] * pow(2, temp_cnt - 1);
				temp_cnt--;
				result.push_back(dir);
			}
			for (int i = result.size() - 1; i >= 0; i--) {
				if (result[i] == 0) {
					cout << "N";
				}
				else if (result[i] == 1) {
					cout << "S";
				}
				else if (result[i] == 2) {
					cout << "E";
				}
				else if (result[i] == 3) {
					cout << "W";
				}
			}
			break;
		}
		for (int i = 0; i < 4; i++) {
			int next_cnt = cur_cnt + 1;
			int next_x = cur_x + x_move[i] * pow(2, next_cnt - 1);
			int next_y = cur_y + y_move[i] * pow(2, next_cnt - 1);
			m[{{next_x, next_y}, next_cnt}] = i;
			q.push({next_x, next_y, next_cnt});
		}
	}
	
}