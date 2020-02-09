/*
날짜: 2020-02-10
분류: Brute Force
TIP: 0일때 예외처리
*/

#include <iostream>
#define MAX 1e9
#pragma warning (disable: 4996)

using namespace std;

int N, M;
int case1 = MAX, case2 = 0;
int result;
int broke[10] = { 0 };

int check(int N);

int main() {
	scanf("%d", &N);
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &broke[i]);
	}

	for (int i = 0; i < 1000000; i++) {

		if (check(N - i) != -1 && N - i >= 0) {
			//printf("%d: %d\n", N - i, check(N - i));
			case1 = check(N - i) + i;
			break;
		}

		if (check(N + i) != -1) {
			//printf("%d: %d\n", N + i, check(N + i));
			case1 = check(N + i) + i;
			break;
		}
	}
	
	case2 = N - 100;

	if (case2 < 0)
		case2 = -case2;

	if (case1 < case2) {
		result = case1;
	}
	else {
		result = case2;
	}

	printf("%d", result);
	return 0;
}

int check(int N) {
	bool can_go = true;
	int press_num = 0;
	if (N == 0) {
		for (int i = 0; i < M; i++) {
			if (0 == broke[i]) {
				return -1;
			}
		}
		return 1;
	}
	else {
		while (N > 0) {
			int a = N % 10;
			for (int i = 0; i < M; i++) {
				if (a == broke[i]) {
					can_go = false;
				}
			}
			if (!can_go) {
				return -1;
			}
			N = N / 10;
			press_num++;
		}
	}

	return press_num;
}