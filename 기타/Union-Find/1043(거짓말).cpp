/*
 * 날짜: 2021-05-12
 * 분류: Union Find
 * TIP: 파티 참가자들을 Union Find를 사용해 Disjoint Set 연산
 */

#include <iostream>
#include <vector>

#pragma warning (disable: 4996)

using namespace std;

int N, M, result = 0;
int root[51] = {0};
vector<int> knownPerson;
vector<int> party[51];

int find_func(int x) {
    if (root[x] == x)
        return x;
    return root[x] = find_func(root[x]);
}

void union_func(int x, int y) {
    int rootX = find_func(x);
    int rootY = find_func(y);
    if (rootX != rootY)
        root[rootX] = rootY;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        root[i] = i;
    int personCount, firstPerson, person;
    cin >> personCount;
    for (int i = 0; i < personCount; i++) {
        cin >> person;
        knownPerson.push_back(person);
    }
    for (int i = 0; i < M; i++) {
        cin >> personCount;
        cin >> firstPerson;
        party[i].push_back(firstPerson);
        for (int j = 0; j < personCount - 1; j++) {
            cin >> person;
            party[i].push_back(person);
            union_func(person, firstPerson);
        }
    }

    for (int i = 0; i < M; i++) {
        bool isOkay = true;
        for (int j = 0; j < party[i].size(); j++) {
            for (int k = 0; k < knownPerson.size(); k++) {
                if (find_func(knownPerson[k]) == find_func(root[party[i][j]])) {
                    isOkay = false;
                    break;
                }
            }
            if (!isOkay)
                break;
        }
        if (isOkay) result++;
    }
    cout << result;
    return 0;
}