/*
날짜: 2020-04-24
분류: Backtracking
*/

#include <iostream>
#include <string>
#pragma warning (disable: 4996)

using namespace std;

int blank = 0;
int board[9][9] = { 0 };
int row[9][10] = { 0 };
int col[9][10] = { 0 };
int box[9][10] = { 0 };
bool finish = false;

void backtracking(int cnt, int start);

int main() {
	string s;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 0; i < 9; i++) {
		cin >> s;
		for (int j = 0; j < 9; j++) {
			board[i][j] = s[j] - '0';
			if (board[i][j] == 0) {
				blank++;
			}
		}
	}

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (board[i][j] != 0) {
				row[i][board[i][j]] = 1;
				box[(i % 9) / 3 * 3 + (j % 9) / 3][board[i][j]] = 1;
			}
			if (board[j][i] != 0) {
				col[i][board[j][i]] = 1;
			}
		}
	}

	backtracking(0, 0);
	return 0;
}

void backtracking(int cnt, int start) {
	if(finish)
		return;

	if (cnt == blank) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << board[i][j];
			}
			cout << "\n";
		}
		finish = true;
		return;
		//exit(0);
	}

	for (int a = start; a < 81; a++) {
		int i = a / 9;
		int j = a % 9;
		if (board[i][j] == 0) {
			for (int k = 1; k < 10; k++) {
				if (!(row[i][k] || col[j][k] || box[(i % 9) / 3 * 3 + (j % 9) / 3][k])) {
					row[i][k] = 1;
					col[j][k] = 1;
					box[(i % 9) / 3 * 3 + (j % 9) / 3][k] = 1;
					board[i][j] = k;
					backtracking(cnt + 1, i * 9 + j + 1);
					row[i][k] = 0;
					col[j][k] = 0;
					box[(i % 9) / 3 * 3 + (j % 9) / 3][k] = 0;
					board[i][j] = 0;
				}
			}
			//break 반드시 필요!
			break;
		}
	}
}

