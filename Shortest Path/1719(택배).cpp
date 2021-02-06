/*
 * 날짜: 2021-02-06
 * 분류: 최단거리, 플로이드 와샬
 * TIP: 다대다 출발지, 도착지의 최단거리를 구해야 해 플로이드 와샬 사용
 * 최단 거리 뿐만 아니라 이동 경로를 관리
 */

#include <iostream>

#define INF 1e9
#pragma warning (disable: 4996)

using namespace std;

int n, m;
int result[201][201] = {0};
int dist[201][201] = {0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j)
                dist[i][j] = INF;
        }
    }

    int start, end, time;
    for (int i = 0; i < m; i++) {
        cin >> start >> end >> time;
        dist[start][end] = time;
        dist[end][start] = time;
        result[start][end] = end;
        result[end][start] = start;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (dist[j][k] > dist[j][i] + dist[i][k]) {
                    dist[j][k] = dist[j][i] + dist[i][k];
                    result[j][k] = result[j][i];
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j)
                cout << result[i][j] << " ";
            else
                cout << "- ";
        }
        cout << "\n";
    }

    return 0;
}