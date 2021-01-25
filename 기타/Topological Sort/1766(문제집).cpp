/*
 * 날짜: 2021-01-26
 * 분류: 위상정렬, 우선순위 큐
 * TIP: 기본 위상정렬 문제이나 가능하면 쉬운 문제부터 풀어야 하는 조건을 우선순위 큐를 사용해 해결
 */

#include <iostream>
#include <vector>
#include <queue>

#pragma warning (disable: 4996)

using namespace std;

int N, M;
int start, finish;
vector<int> v[32001];
priority_queue<int> q;
int inEdgeNum[32001] = {0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        cin >> start >> finish;
        v[start].push_back(finish);
        inEdgeNum[finish]++;
    }

    for (int i = 1; i <= N; i++) {
        if (inEdgeNum[i] == 0)
            q.push(-i);
    }

    while (!q.empty()) {
        int cur = -q.top();
        cout << cur << " ";
        q.pop();
        for (int i = 0; i < v[cur].size(); i++) {
            int next = v[cur][i];
            inEdgeNum[next]--;
            if (inEdgeNum[next] == 0)
                q.push(-next);
        }
    }

    return 0;
}