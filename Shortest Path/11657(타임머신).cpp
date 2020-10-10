/*
 * 날짜: 2020-10-10
 * 분류: 최단거리, 벨만 포드
 * TIP: result 배열을 int로 선언할 경우 overflow, underflow 발생
 *      벨만 포드에서 단순히 음의 사이클 존재 찾는다?
 *      => N번 반복 후 한 번 더 반복해서 변하는 거 있는지
 *      출발점에서 갈 수 있는 음의 사이클 존재 찾는다?
 *      => here 출발지 dist 값이 INF면 무시(continue)
 */

#include <iostream>
#include <vector>
#pragma warning(disable: 4996)
#define INF 1e18

using namespace std;

int n, m;
int a, b, c;
vector<pair<int, int>> adj[501];
long long result[501] = {0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    for (int i = 1; i <= n; i++)
        result[i] = INF;
    result[1] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 0; k < adj[j].size(); k++) {
                int next = adj[j][k].first;
                int cost = adj[j][k].second;
                if(result[j] == INF)
                    continue;
                if (result[next] > result[j] + cost)
                    result[next] = result[j] + cost;
            }
        }
    }

    for (int j = 1; j <= n; j++) {
        for (int k = 0; k < adj[j].size(); k++) {
            int next = adj[j][k].first;
            int cost = adj[j][k].second;
            if(result[j] == INF)
                continue;
            if (result[next] > result[j] + cost) {
                cout << "-1";
                exit(0);
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        if (result[i] == INF)
            cout << "-1" << "\n";
        else
            cout << result[i] << "\n";
    }

    return 0;
}