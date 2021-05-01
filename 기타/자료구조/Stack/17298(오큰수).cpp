/*
 * 날짜: 2021-05-01
 * 분류: Stack
 * TIP: 스택을 사용해 O(n^2) 개선 가능
 */

#include <iostream>
#include <stack>
#include <cstring>

#pragma warning (disable: 4996)

using namespace std;

stack<int> s;
int N;
int arr[1000001] = {0};
int result[1000001] = {0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    memset(result, -1, sizeof result);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        while (!s.empty() && arr[i] > arr[s.top()]) {
            // cout << s.top() << " " << i << " " << arr[i] << endl;
            result[s.top()] = arr[i];
            s.pop();
        }
        s.push((i));
    }

    for (int i = 0; i < N; i++)
        cout << result[i] << " ";
    return 0;
}