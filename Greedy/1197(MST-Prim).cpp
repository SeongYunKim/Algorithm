/*
 * 날짜: 2021-04-06
 * 분류: MST, Prim(Greedy)
 * TIP: 한 정점으로 부터 이전 단계 사이클 만들지 않도록 확장하며 그리디 (V-1개의 간선 연결할 때 까지)
 * 시간 복잡도: O(n^2) => 간선 개수 많을 때 유리 (Kruskal O(E*logE))
 * https://gmlwjd9405.github.io/2018/08/30/algorithm-prim-mst.html
 */

#include <iostream>
#include <queue>
#include <algorithm>

#pragma warning (disable: 4996)

using namespace std;

int V, E;
int result;
priority_queue<pair<int, pair<int, int>>> pq;
vector<pair<int, int>> v[10001];
bool visited[10001] = {false};

// 갈 수 있는 간선을 모두 우선순위 큐에 넣고 사이클을 만들지 않는 제일 짧은 간선을 계산
void prim(int start) {
    visited[start] = true;
    for(int i = 0; i < v[start].size(); i++) {
        if (!visited[v[start][i].first])
            pq.push({-v[start][i].second, {start, v[start][i].first}});
    }

    while(!pq.empty()) {
        pair<int, pair<int, int>> p = pq.top();
        pq.pop();
        if (!visited[p.second.second]) {
            result += (-p.first);
            prim(p.second.second);
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> V >> E;
    int A, B, C;
    for (int i = 0; i < E; i++) {
        cin >> A >> B >> C;
        v[A].push_back({B, C});
        v[B].push_back({A, C});
    }
    /*
    for (int i = 0; i < v[1].size(); i++)
        pq.push({-v[1][i].second, {1, v[1][i].first}});
    visited[1] = true;
    while (V > 1) {
        pair<int, pair<int, int>> p;
        p = pq.top();
        pq.pop();
        if (!visited[p.second.second]) {
            visited[p.second.second] = true;
            V--;
            for (int i = 0; i < v[p.second.second].size(); i++) {
                if (!visited[v[p.second.second][i].first]) {
                    pq.push({-v[p.second.second][i].second, {p.second.second, v[p.second.second][i].first}});
                }
            }
            result += (-p.first);
        }
    }
    */
    prim(1);
    cout << result;
    return 0;
}