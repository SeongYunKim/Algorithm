/*
 * 날짜: 2021-01-27
 * 분류: BFS
 * TIP: 하이퍼 튜를 모두 간선으로 계산하면
 * 최대 간선 개수가 약 (하이퍼튜브가 서로 연결하는 역의 개수)^2 * (하이퍼튜브 수)
 * 로 메모리 초과가 발생.
 * 하이퍼튜브 또한 정점으로 계산하면
 * 정점의 개수는 약 (하이퍼튜브의 수) 만큼 증가하지만
 * 최대 간선 개수는 약 (하이퍼튜브가 서로 연결하는 역의 개수) * (하이퍼튜브의 수)로 감소.
 * 하이퍼튜브 간선에 방문했을 때는 거리를 증가시키지 않으면 BFS 진행
 */

#include <iostream>
#include <queue>
#include <vector>

#pragma warning (disable: 4996)

using namespace std;

int N, K, M;
bool visited[101002] = {0};
int dist[101002] = {0};
int temp[1001] = {0};
vector<int> v[101002];
queue<int> q;

int bfs() {
    int canReach = false;
    q.push(1);
    visited[1] = true;
    dist[1] = 1;
    while (!q.empty()) {
        int front = q.front();
        q.pop();
        if (front == N) {
            canReach = true;
            return dist[N];
        }
        for (int i = 0; i < v[front].size(); i++) {
            int next = v[front][i];
            if (!visited[next]) {
                q.push(next);
                visited[next] = true;
                if (next > N)
                    dist[next] = dist[front];
                else
                    dist[next] = dist[front] + 1;
            }
        }
    }
    if (!canReach)
        return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K >> M;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < K; j++) {
            cin >> temp[j];
            v[N + i + 1].push_back(temp[j]);
            v[temp[j]].push_back(N + i + 1);
        }
    }

    cout << bfs();
    return 0;
}
