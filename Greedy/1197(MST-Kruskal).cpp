/*
 * 날짜: 2021-04-06
 * 분류: MST, Kruskal(Greedy)
 * TIP: 간선간 거리로 오름차순 정렬 후 사이클 만들지 않도록 그리디 (V-1개의 간선 연결할 때 까지)
 * Union-Find로 같은 트리 내에 있는지(사이클 여부) 검사
 * 시간 복잡도: O(E*logE) => 간선 개수 적을 때 유리 (Prim은 O(n^2))
 * https://gmlwjd9405.github.io/2018/08/29/algorithm-kruskal-mst.html
 */

#include <iostream>
#include <queue>
#include <algorithm>

#pragma warning (disable: 4996)

using namespace std;

int V, E;
int result;
int root[10001];
priority_queue<pair<int, pair<int, int>>> pq;

int find_union(int x) {
    if (root[x] == x)
        return x;
    return root[x] = find_union(root[x]);
}

void make_union(int x, int y) {
    int rootX = find_union(x);
    int rootY = find_union(y);
    if (rootX != rootY)
        root[rootX] = rootY;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> V >> E;
    for (int i = 1; i <= V; i++)
        root[i] = i;
    int A, B, C;
    for (int i = 0; i < E; i++) {
        cin >> A >> B >> C;
        pq.push({-C, {A, B}});
    }
    while (V > 1) {
        pair<int, pair<int, int>> p = pq.top();
        pq.pop();
        if (find_union(p.second.first) != find_union(p.second.second)) {
            make_union(p.second.first, p.second.second);
            result += (-p.first);
            V--;
        }
    }
    cout << result;
    return 0;
}
