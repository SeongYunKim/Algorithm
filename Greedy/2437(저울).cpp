/*
 * 날짜: 2021-02-17
 * 분류: Greedy
 * TIP: 무게로 정렬 후 순회하며
 * 최초로 등장하는 (누적 합 + 1)보다 큰 무게
 */

#include <iostream>
#include <algorithm>
#pragma warning (disable: 4996)

using namespace std;

int N;
int weight[1001] = { 0 };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> weight[i];

    sort(weight, weight + N);

    if(weight[0] != 1) {
        cout << "1";
        return 0;
    }

    int sum = 1;
    for(int i = 1; i < N; i++) {
        if(sum + 1 < weight[i]) {
            cout << sum + 1;
            return 0;
        }
        sum += weight[i];
    }
    cout << sum + 1;
    return 0;
}