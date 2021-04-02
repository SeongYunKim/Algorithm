#include <iostream>
#include <algorithm>

#pragma warning (disable: 4996)

using namespace std;

int N, K, W, V;
int value[101] = { 0 };
int weight[101] = { 0 };
int dp[101][100001]= { 0 };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> W >> V;
        value[i + 1] = V;
        weight[i + 1] = W;
    }
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= K; j++) {
            if(j - weight[i] >= 0)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[N][K];
    return 0;
}