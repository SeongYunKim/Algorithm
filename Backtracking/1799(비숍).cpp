/*
��¥: 2020-04-03
�з�: Backtracking
TIP: ��� ���� ���� ���� ���� �ִ밪�� ������Ʈ ���ָ� �ݺ��� ���� �� ���� Backtracking
ü������ �� ĭ�� ���� ĭ�� �����Ͽ� O(2^N*N)�� O(2^(N/2)*(N/2))��
*/

#include <iostream>
#pragma warning (disable: 4996)

using namespace std;

int n, blank = 0;
int max_result = 0;
int board[11][11] = { 0 };
int color[11][11] = { 0 };
int piece[11][11] = { 0 };
int answer[2] = { 0 };
int move_x[4] = { 1, 1, -1, -1 };
int move_y[4] = { 1, -1, 1, -1 };

void backtracking(int color, int start, int piece_num);
bool bishop(int i, int j, int x, int y);
bool check(int i, int j);

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &board[i][j]);
			if (board[i][j] == 1) {
				blank++;
				if (i % 2 == 0) {
					if (j % 2 == 0) {
						color[i][j] = 1;
					}
				}
				else {
					if (j % 2 != 0) {
						color[i][j] = 1;
					}
				}
			}
		}
	}

	backtracking(0, 0, 0);
	backtracking(1, 0, 0);

	printf("%d", answer[0] + answer[1]);
	return 0;
}

//col: ü�� ���� ĭ�� ��, start: Ž���� ������ ĭ, piece_num: ������� ü�� ���� ���� �� ��
void backtracking(int col, int start, int piece_num) {
	
	if (piece_num > answer[col]) {
		answer[col] = piece_num;
		/*
		printf("answer: %d\n", piece_num);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				printf("%d ", piece[i][j]);
			}
			printf("\n");
		}
		*/
	}

	for (int a = start; a < n * n; a++) {
		int x = a / n;
		int y = a % n;
		if (board[x][y] == 1 && color[x][y] == col) {

			if (check(x, y)) {
				piece[x][y] = 1;
				backtracking(col, a + 1, piece_num + 1);
				piece[x][y] = 0;
			}
		}
	}
}

bool bishop(int i, int j, int x, int y) {
	int x_diff = x - i;
	int y_diff = y - j;
	if (x_diff == -y_diff || x_diff == y_diff) {
		return false;
	}
	return true;
}

bool check(int x, int y) {
	int cur_x, cur_y;
	for (int i = 0; i < 4; i++) {
		for (int j = 1; j < n; j++) {
			cur_x = x + move_x[i] * j;
			cur_y = y + move_y[i] * j;
			if (cur_x < 0 || cur_x >= n || cur_y < 0 || cur_y >= n)
				continue;
			if (piece[cur_x][cur_y] == 1)
				return false;
		}
	}
	return true;
}