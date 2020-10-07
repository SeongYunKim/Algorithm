/*
 * 날짜: 2020-10-08
 * 분류: Binary Search, lower_bound, upper_bound
 * TIP: Binary Search를 통해 특정 value보다 큰 원소의 개수를 O(logn)에 구하기
 */

#include <iostream>
#include <algorithm>
#pragma warning(disable : 4996)
#define INF 1e9

using namespace std;

int n, h, result = INF, cnt = 1;
int arr1[100001] = {0};
int arr2[100001] = {0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    scanf("%d %d", &n, &h);
    int temp;
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        if (i % 2 == 0)
            arr1[i / 2] = temp;
        else
            arr2[i / 2] = temp;
    }
    sort(arr1, arr1 + n / 2);
    sort(arr2, arr2 + n / 2);
    int sum, index1, index2;
    for (int i = 1; i <= h; i++) {
        sum = 0;
        index1 = lower_bound(arr1, arr1 + n / 2, i) - arr1;
        index2 = lower_bound(arr2, arr2 + n / 2, h - i + 1) - arr2;
        // index2 = upper_bound(arr2, arr2 + n / 2, h - i) - arr2;
        sum += (n / 2 - index1) + (n / 2 - index2);
        if (result > sum) {
            result = sum;
            cnt = 1;
        } else if (result == sum) {
            cnt++;
        }
    }
    printf("%d %d", result, cnt);
    return 0;
}