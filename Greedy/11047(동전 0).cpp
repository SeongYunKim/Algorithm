/*
날짜: 2020-01-30
분류: Greedy
*/

#include <iostream>
#pragma warning (disable: 4996)

using namespace std;

int N, K;
int A[10] = { 0 };

int main() {
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}

	int index = N - 1;
	int coin = 0;
	while(K != 0) {
		coin += K / A[index];
		K = K % A[index];
		index--;
	}
	printf("%d", coin);
	return 0;
}