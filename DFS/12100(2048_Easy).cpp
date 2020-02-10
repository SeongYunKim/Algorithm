/*
날짜: 2020-02-10
분류: DFS, Backtracking, Brute Fprce
TIP: vector.size()의 반환형은 unsigned int이다.
     따라서 비어있는(size가 0인) vector의 size()에 -1을 하면 -1이 아닌 큰 양수값이 나온다.
	 (int)vector.size() - 1를 통해 형변환을 해준다면 원하는 -1을 얻을 수 있다.

	 BackTracking:
	 if(종료조건) -> return
	 else -> 값 변경, 재귀 호출, 값 원상복구
*/


#include <iostream>
#include <vector>
#pragma warning (disable: 4996)

using namespace std;

int N;
int board[21][21] = { 0 };
int result = -1;

void dfs(int cnt);
void move(int num, int cnt);

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf(" %d", &board[i][j]);
		}
	}
	dfs(0);
	printf("%d", result);
	return 0;
}

void dfs(int cnt) {
	if (cnt == 5) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (result < board[i][j]) {
					result = board[i][j];
				}
			}
		}
		return;
	}
	int copy[21][21];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			copy[i][j] = board[i][j];
		}
	}

	for (int i = 0; i < 4; i++) {
		move(i, cnt);
		dfs(cnt + 1);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				board[i][j] = copy[i][j];
			}
		}
	}
}

void move(int num, int cnt) {
	vector<int> v[21];
	if (num == 0) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (board[i][j] != 0) {
					v[i].push_back(board[i][j]);
				}
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < (int)v[i].size() - 1; j++) {
				if (v[i][j] == v[i][j + 1]) {
					v[i][j] *= 2;
					v[i][j + 1] = 0;
				}
			}
		}

		for (int i = 0; i < N; i++) {
			int k = 0;
			for (int j = 0; j < v[i].size(); j++) {
				if (v[i][j] != 0) {
					board[i][k] = v[i][j];
					k++;
				}
			}
			for (int a = k; a < N; a++) {
				board[i][a] = 0;
			}
		}
	}

	else if (num == 1) {
		for (int i = 0; i < N; i++) {
			for (int j = N - 1; j >= 0; j--) {
				if (board[i][j] != 0) {
					v[i].push_back(board[i][j]);
				}
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < (int)v[i].size() - 1; j++) {
				if (v[i][j] == v[i][j + 1]) {
					v[i][j] *= 2;
					v[i][j + 1] = 0;
				}
			}
		}

		for (int i = 0; i < N; i++) {
			int k = N - 1;
			for (int j = 0; j < v[i].size(); j++) {
				if (v[i][j] != 0) {
					board[i][k] = v[i][j];
					k--;
				}
			}
			for (int a = k; a >= 0; a--) {
				board[i][a] = 0;
			}
		}
	}

	else if (num == 2) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (board[j][i] != 0) {
					v[i].push_back(board[j][i]);
				}
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < (int)v[i].size() - 1; j++) {
				if (v[i][j] == v[i][j + 1]) {
					v[i][j] *= 2;
					v[i][j + 1] = 0;
				}
			}
		}

		for (int i = 0; i < N; i++) {
			int k = 0;
			for (int j = 0; j < v[i].size(); j++) {
				if (v[i][j] != 0) {
					board[k][i] = v[i][j];
					k++;
				}
			}
			for (int a = k; a < N; a++) {
				board[a][i] = 0;
			}
		}
	}

	else if (num == 3) {
		for (int i = 0; i < N; i++) {
			for (int j = N - 1; j >= 0; j--) {
				if (board[j][i] != 0) {
					v[i].push_back(board[j][i]);
				}
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < (int)v[i].size() - 1; j++) {
				if (v[i][j] == v[i][j + 1]) {
					v[i][j] *= 2;
					v[i][j + 1] = 0;
				}
			}
		}

		for (int i = 0; i < N; i++) {
			int k = N - 1;
			for (int j = 0; j < v[i].size(); j++) {
				if (v[i][j] != 0) {
					board[k][i] = v[i][j];
					k--;
				}
			}
			for (int a = k; a >= 0; a--) {
				board[a][i] = 0;
			}
		}
	}

	/*
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", board[i][j]);
		}
		printf("\n");
	}
	*/
}
