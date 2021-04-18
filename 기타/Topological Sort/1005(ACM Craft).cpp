/*
 * 날짜: 2021-04-19
 * 분류: 위상 정렬(Topological Sort)
 * TIP: 전형적인 위상 정렬 문제
 * inDegree가 0일 때까지 resultTime이 더 클 때 업데이트
 */

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#pragma warning (disable: 4996)

using namespace std;

int T, N, K, W, X, Y;
vector<int> v[100001];
queue<int> q;
int buildTime[100001] = {0};
int inDegree[100001] = {0};
long long resultTime[100001] = {0};

void init() {
    while (!q.empty())
        q.pop();
    for (int i = 0; i < 100001; i++)
        v[i].clear();
    memset(buildTime, 0, sizeof buildTime);
    memset(inDegree, 0, sizeof inDegree);
    memset(resultTime, 0, sizeof resultTime);
}

void topologicalSort() {
    for (int i = 1; i <= N; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
            resultTime[i] = buildTime[i];
            if (i == W) {
                cout << resultTime[i] << '\n';
                return;
            }
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < v[cur].size(); i++) {
            int next = v[cur][i];
            inDegree[next]--;
            if (resultTime[next] < resultTime[cur] + buildTime[next])
                resultTime[next] = resultTime[cur] + buildTime[next];
            if (inDegree[next] == 0) {
                q.push(next);
                if (next == W) {
                    cout << resultTime[next] << '\n';
                    return;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while (T--) {
        init();
        cin >> N >> K;
        for (int i = 0; i < N; i++)
            cin >> buildTime[i + 1];
        for (int i = 0; i < K; i++) {
            cin >> X >> Y;
            v[X].push_back(Y);
            inDegree[Y]++;
        }
        cin >> W;
        topologicalSort();
    }
    return 0;
}