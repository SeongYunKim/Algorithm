/*
날짜: 2020-01-20
분류: DP
*/

#include <iostream>
#pragma warning (disable: 4996)

using namespace std;

int N;
int map[101][101] = { 0 };
long long answer[101][101] = { 0 };

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	answer[1][1] = 1;
	for (int i = 1; i < N; i++) {
		for (int j = 0; j <= N - i; j++) {
			if (i + map[i + j][i] + j <= N)
				answer[i + map[i + j][i] + j][i] += answer[i + j][i];
			if (i + map[i + j][i] <= N)
				answer[i + j][i + map[i + j][i]] += answer[i + j][i];
			if (j != 0) {
				if (i + map[i][i + j] + j <= N)
					answer[i][i + map[i][i + j] + j] += answer[i][i + j];
				if (i + map[i][i + j] <= N)
					answer[i + map[i][i + j]][i + j] += answer[i][i + j];
			}
		}
	}
	printf("%lld", answer[N][N]);
	return 0;
}