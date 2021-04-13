/*
 * 날짜: 2021-04-14
 * 분류: DP
 * TIP:
 * 실수 포인트 1. DP 인덱스값 허용값 밖으로 벗어나는지 항상 체크!
 * 실수 포인트 2. 자료형 범위 항상 조심! (long long)
 */

#include <iostream>

#pragma warning (disable: 4996)

using namespace std;

// 0: 6,
// 1: 2,
// 2: 5,
// 3: 5,
// 4: 4,
// 5: 5,
// 6: 6,
// 7: 3,
// 8: 7,
// 9: 6;
int num[8] = {0};
long long dp[101] = {0};
int t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    num[2] = 1; dp[2] = 1;
    num[3] = 7; dp[3] = 7;
    num[4] = 4; dp[4] = 4;
    num[5] = 2; dp[5] = 2;
    num[6] = 0; dp[6] = 6;
    num[7] = 8; dp[7] = 8;
    for (int i = 8; i <= 100; i++) {
        long long min = dp[i - 2] * 10 + num[2];
        for (int j = 3; j <= 7; j++) {
            if (i - j >= 2 && min > dp[i - j] * 10 + num[j])
                min = dp[i - j] * 10 + num[j];
        }
        dp[i] = min;
    }
    cin >> t;
    while (t--) {
        int num;
        cin >> num;
        cout << dp[num] << ' ';
        if (num % 2 == 0)
            cout << '1';
        else
            cout << '7';
        for (int i = 0; i < num / 2 - 1; i++) {
            cout << '1';
        }
        cout << '\n';
    }
    return 0;
}