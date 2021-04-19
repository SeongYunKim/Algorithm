/*
 * 날짜: 2021-04-20
 * 분류: BFS
 * TIP: check: 해당 노드로부터 DFS가 완료되면 true
 */

#include <iostream>
#include <cstring>

#define MAX 100001

#pragma warning (disable: 4996)

using namespace std;

int T, n, cnt = 0;
int wantMember[MAX] = {0};
bool visited[MAX] = {false}, check[MAX] = {false};

void dfs(int cur) {
    visited[cur] = true;
    int next = wantMember[cur];

    if (visited[next]) {
        if (!check[next]) {
            for (int i = next; i != cur; i = wantMember[i])
                cnt++;
            cnt++;
        }
    } else {
        dfs(next);
    }

    check[cur] = true;
}

void init() {
    cnt = 0;
    memset(wantMember, 0, sizeof wantMember);
    memset(visited, 0, sizeof visited);
    memset(check, 0, sizeof check);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while (T--) {
        init();
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> wantMember[i];

        for (int i = 1; i <= n; i++) {
            if (visited[i])
                continue;
            dfs(i);
        }

        cout << n - cnt << '\n';
    }
    return 0;
}