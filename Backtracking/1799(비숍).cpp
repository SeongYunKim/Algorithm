/*
날짜: 2020-04-03
분류: Backtracking
TIP: 재귀 종료 조건 설정 없이 최대값을 업데이트 해주며 반복이 끝날 때 까지 Backtracking
체스판의 흰 칸과 검은 칸을 구분하여 O(2^N*N)을 O(2^(N/2)*(N/2))로
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

//col: 체스 보드 칸의 색, start: 탐색을 시작할 칸, piece_num: 현재까지 체스 보드 위의 말 수
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