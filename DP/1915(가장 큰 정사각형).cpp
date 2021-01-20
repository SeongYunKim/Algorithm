/*
날짜: 2021-01-20
분류: DP
TIP: dp[i][j] = (i, j)를 오른쪽 아래 꼭지로 하는 최대 크기 정사각형 한 변 길이
*/

#include <iostream>
#include <string>
#pragma warning (disable: 4996)

using namespace std;

int n, m;
string s;
int arr[1002][1002] = {0};
int dp[1002][1002] = {0};

int getMin(int a, int b, int c) {
    if (a < b) {
        if (a < c)
            return a;
        else
            return c;
    } else {
        if (b < c)
            return b;
        else
            return c;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        for (int j = 1; j <= m; j++) {
            arr[i][j] = s[j - 1] - '0';
            dp[i][j] = arr[i][j];
        }
    }

    int max = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (dp[i][j] > 0) {
                int min = getMin(dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]);
                if(min > 0)
                    dp[i][j] = min + 1;
            }
            if(dp[i][j] > max)
                max = dp[i][j];
        }
    }

    cout << max * max;
    return 0;
}