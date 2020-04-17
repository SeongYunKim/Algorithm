/*
날짜: 2020-04-17
분류: Greedy
TIP: 어떤 색 공을 어느 쪽 끝으로 이동할 것인가?
만 결정하면 이동 순서와 최소 이동 횟수는 정해진다
*/

#include <iostream>
#include <algorithm>
#pragma warning (disable: 4996)

using namespace std;

int n;
int ball[500001] = { 0 };
int ball_num[2] = { 0 };
int end_ball[2] = { 0 };
int temp_result[4] = { 0 };

int main() {
	scanf("%d", &n);
	char c;
	for (int i = 0; i < n; i++) {
		scanf(" %c", &c);
		ball[i] = ((c == 'B') ? 0 : 1);
		ball_num[ball[i]]++;
	}

	//end_ball[0] 왼쪽 끝 연속된 공 개수
	//end_ball[1] 오른쪽 끝 연속된 공 개수
	for (int i = 0; i < n; i++) {
		if (ball[i] == ball[0])
			end_ball[0]++;
		else break;
	}

	for (int i = n - 1; i >= 0; i--) {
		if (ball[i] == ball[n - 1])
			end_ball[1]++;
		else break;
	}

	for (int i = 0; i < 2; i++) {
		if (ball[0] == i)
			temp_result[i * 2] = ball_num[i] - end_ball[0];
		else
			temp_result[i * 2] = ball_num[i];
		if (ball[n - 1] == i)
			temp_result[i * 2 + 1] = ball_num[i] - end_ball[1];
		else
			temp_result[i * 2 + 1] = ball_num[i];
	}
	sort(temp_result, temp_result + 4);
	printf("%d", temp_result[0]);
}