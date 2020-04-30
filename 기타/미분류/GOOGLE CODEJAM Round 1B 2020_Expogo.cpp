/*
��¥: 2020-04-21
�з�: ���̵��
TIP: BFS ���� Ž���� �ð��ʰ�
ù �̵��� Ȧ����� ���� �̿��Ͽ� Ȧ�� ��ǥ�� �������� �̵��ϰ�
�̵��� ��ǥ�� ���� ���� ��ǥ �� ����� ��ǥ�� ���
*/

#include <iostream>
#include <vector>
#pragma warning (disable: 4996)

using namespace std;

int t;
int x, y;
int unit_move[2] = { 1, -1 };
vector<int> result;

void init() {
	result.clear();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	for (int a = 1; a <= t; a++) {
		init();
		cin >> x >> y;
		int target_x = x, target_y = y;
		cout << "Case #" << a << ": ";
		if ((x + y) % 2) {
			while (target_x * target_y != 0 || !(target_x + target_y == 1 || target_x + target_y == -1)) {
				for (int i = 0; i < 2; i++) {
					if ((target_x + target_y - unit_move[i]) / 2 % 2) {
						if (target_x % 2) {
							target_x = (target_x - unit_move[i]) / 2;
							target_y /= 2;
							result.push_back(i);
							break;
						}
						if (target_y % 2) {
							target_x /= 2;
							target_y = (target_y - unit_move[i]) / 2;
							result.push_back(2 + i);
							break;
						}
					}
				}
			}
			for (int i = 0; i < result.size(); i++) {
				switch (result[i]) {
				case 0:
					cout << "E"; break;
				case 1:
					cout << "W"; break;
				case 2:
					cout << "N"; break;
				case 3:
					cout << "S"; break;
				}
			}
			switch (target_x) {
			case 1:
				cout << "E"; break;
			case -1:
				cout << "W"; break;
			}
			switch (target_y) {
			case 1:
				cout << "N"; break;
			case -1:
				cout << "S"; break;
			}
		}
		else {
			cout << "IMPOSSIBLE";
		}
		cout << "\n";
	}
	return 0;
}