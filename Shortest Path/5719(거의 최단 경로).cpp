/*
 * 날짜: 2021-02-07
 * 분류: 다익스트라, BFS
 * TIP: trace에 이전 방문 노드 저장
 * 같은 최단 거리의 경로가 복수 개
 * 복수 최단 거리간 노선 공유할 수 있으므로
 * visited 사용해 중복된 노선 제거 X (메모리 초과 해결)
 */

#include <iostream>
#include <queue>
#include <vector>

#define INF 1e9

#pragma warning (disable: 4996)

using namespace std;

int n, m;
int s, d;
int start, finish, dis;
vector<pair<int, int>> v[501];
vector<int> trace[501];
bool visited[501][501] = {0};
long long int dist[501] = {0};

void dijkstra() {
    dist[s] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, s});
    while (!pq.empty()) {
        pair<int, int> p = pq.top();
        int curDist = -p.first;
        int curNode = p.second;
        pq.pop();

        for (int i = 0; i < v[curNode].size(); i++) {
            int nextNode = v[curNode][i].first;
            int nextDist = v[curNode][i].second;
            if (curDist + nextDist < dist[nextNode]) {
                dist[nextNode] = curDist + nextDist;
                pq.push({-dist[nextNode], nextNode});
                // 새로운 최단 거리 업데이트 시 기존 이전 노드 삭제
                trace[nextNode].clear();
                trace[nextNode].push_back(curNode);
            } else if (curDist + nextDist == dist[nextNode]) {
                // 같은 최단 거리의 경로가 복수개
                trace[nextNode].push_back(curNode);
            }
        }
    }
}

void bfs() {
    queue<int> q;
    q.push(d);
    while (!q.empty()) {
        int curNode = q.front();
        q.pop();
        for (int i = 0; i < trace[curNode].size(); i++) {
            int nextNode = trace[curNode][i];
            if (visited[curNode][nextNode])
                continue;
            visited[curNode][nextNode] = true;
            for (int j = 0; j < v[nextNode].size(); j++) {
                if (v[nextNode][j].first == curNode)
                    v[nextNode][j].second = INF;
            }
            q.push(nextNode);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        for (int i = 0; i < 501; i++) {
            for (int j = 0; j < 501; j++)
                visited[i][j] = false;
            v[i].clear();
            trace[i].clear();
            dist[i] = INF;
        }
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;
        cin >> s >> d;
        for (int i = 0; i < m; i++) {
            cin >> start >> finish >> dis;
            v[start].push_back({finish, dis});
        }
        dijkstra();
        bfs();
        for (int i = 0; i < 501; i++)
            dist[i] = INF;
        dijkstra();
        if (dist[d] == INF)
            cout << "-1\n";
        else
            cout << dist[d] << "\n";
    }
}