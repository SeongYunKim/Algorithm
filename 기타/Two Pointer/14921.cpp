/*
 * 날짜: 2021-08-30
 * 분류: 투포인터
 * TIP: 더한 값이 0보다 작으면 right--, 크면 left++
 */

#include <iostream>
#include <cmath>

#define MAX 1e9

#pragma warning (disable: 4996)

using namespace std;

int N;
int result = 2 * MAX;
int arr[100001] = {0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    int left = 0, right = N - 1;
    while (true) {
        if (left == right) {
            break;
        }
        int sum = arr[left] + arr[right];
        if (abs(result) > abs(sum)) {
            result = sum;
        }
        if (sum > 0) {
            right--;
        } else if (sum < 0) {
            left++;
        } else {
            result = 0;
            break;
        }
    }
    cout << result;
    return 0;
}