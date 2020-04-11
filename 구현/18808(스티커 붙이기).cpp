/*
날짜: 2020-04-11
분류: 구현
TIP: 스티커를 회전시키며 판에 끼워맞추기
*/

#include <iostream>
#include <vector>
#pragma warning (disable: 4996)

using namespace std;

int n, m, k;
int r, c;
int input;
int result = 0;
int sticker[100][4][10][10] = { 0 };
int notebook[40][40] = { 0 };
vector<pair<int, int>> sticker_size;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		cin >> r >> c;
		sticker_size.push_back({ r, c });

		for (int a = 0; a < r; a++) {
			for (int b = 0; b < c; b++) {
				cin >> input;
				sticker[i][0][a][b] = input;
				sticker[i][1][b][r - 1 - a] = input;
				sticker[i][2][r - 1 - a][c - 1 - b] = input;
				sticker[i][3][c - 1 - b][a] = input;
			}
		}
	}

	bool flag = true;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < 4; j++) {
			int row, col;
			if (j % 2 == 0) {
				row = sticker_size[i].first;
				col = sticker_size[i].second;
			}
			else {
				row = sticker_size[i].second;
				col = sticker_size[i].first;
			}
			if (n - row < 0 || m - col < 0) {
				flag = false;
			}
			for (int a = 0; a <= n - row; a++) {
				for (int b = 0; b <= m - col; b++) {
					flag = true;
					for (int x = 0; x < row; x++) {
						for (int y = 0; y < col; y++) {
							if (sticker[i][j][x][y] == 1) {
								if (notebook[a + x][b + y] == 1) {
									flag = false;
								}
							}
						}
					}

					if (flag) {
						for (int x = 0; x < row; x++) {
							for (int y = 0; y < col; y++) {
								if (sticker[i][j][x][y] == 1) {
									notebook[a + x][b + y] = 1;
								}
							}
						}
						break;
					}
				}
				if (flag)
					break;
			}
			if (flag) 
				break;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			//printf("%d ", notebook[i][j]);
			if(notebook[i][j] == 1){
				result++;
			}
		}
		//printf("\n");
	}

	printf("%d", result);
	return 0;
}