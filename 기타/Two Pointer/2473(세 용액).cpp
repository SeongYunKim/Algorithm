/*
날짜: 2020-04-08
분류: 구현
TIP: K에 가장 가까운 두 수의 합을 O(N)에 구하는 방법?
left = 0, right = n - 1 초기화 후
case1) arr[left] + arr[right] > K 이면 right--
case2) arr[left] + arr[right] < K 이면 left++
하며 O(N)에 두 수의 조합을 구하기

그렇다면 세 수의 합은?
N을 순회하며 각 N에 대해 두 수의 합을 구하는 알고리즘 적용 => O(N^2)
*/

#include <iostream>
#include <algorithm>
#pragma warning (disable: 4996)

using namespace std;

int n;
long long min_sum = 1e9 * 3 + 1;
long long  arr[5001] = { 0 };
long long  result[3] = { 0 };

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
	}
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		int left = 0;
		int right = n - 1;
		while (left < right) {
			if (left == i)
				left++;
			else if (right == i)
				right--;
			else {
				long long sum = arr[left] + arr[right] + arr[i];
				if (sum < 0)
					sum = -sum;
				if (sum < min_sum) {
					min_sum = sum;
					result[0] = arr[left];
					result[1] = arr[right];
					result[2] = arr[i];
				}

				if (arr[left] + arr[right] < -arr[i]) {
					left++;
				}
				else if (arr[left] + arr[right] > -arr[i]) {
					right--;
				}
				else {
					break;
				}
			}

		}
	}
	sort(result, result + 3);
	for (int i = 0; i < 3; i++) {
		printf("%lld ", result[i]);
	}
}