/*
 * 날짜: 2021-01-27
 * 분류: DP
 * TIP: 점화식은 Easy. 하지만 메모리 제한이 빡셈.
 * 바로 이전 줄의 DP 배열 값만 가지고 있으면 되므로 적은 메모리로도 풀 수 있음.
 */

#include <iostream>
#include <algorithm>

#pragma warning (disable: 4996)

using namespace std;

int N;
int board[3] = {0};
int minDp[2][3] = {0};
int maxDp[2][3] = {0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> board[j];
            if (j == 0) {
                maxDp[(i + 1) % 2][0] = board[0] + max(maxDp[i % 2][0], maxDp[i % 2][1]);
                minDp[(i + 1) % 2][0] = board[0] + min(minDp[i % 2][0], minDp[i % 2][1]);
            } else if (j == 1) {
                maxDp[(i + 1) % 2][1] = board[1] + max(max(maxDp[i % 2][0], maxDp[i % 2][1]), maxDp[i % 2][2]);
                minDp[(i + 1) % 2][1] = board[1] + min(min(minDp[i % 2][0], minDp[i % 2][1]), minDp[i % 2][2]);
            } else if (j == 2) {
                maxDp[(i + 1) % 2][2] = board[2] + max(maxDp[i % 2][2], maxDp[i % 2][1]);
                minDp[(i + 1) % 2][2] = board[2] + min(minDp[i % 2][2], minDp[i % 2][1]);
            }
        }
    }

    int row = N % 2;
    int min = minDp[row][0];
    int max = maxDp[row][0];
    for (int i = 0; i < 3; i++) {
            if (minDp[row][i] < min)
                min = minDp[row][i];
            if (maxDp[row][i] > max)
                max = maxDp[row][i];
    }

    cout << max << " " << min;

    return 0;
}