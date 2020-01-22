/*
날짜: 2020-01-22
분류: Binary Search
TIP: low_boundm, high_bound로 Binary Search에서 num의 개수 구하기
*/

#include <iostream>
#include <algorithm>
#pragma warning (disable: 4996)

using namespace std;

int A[4000], B[4000], C[4000], D[4000];
int sum1[16000000], sum2[16000000];
int n;
long long int result = 0;

long long int binary_search(int num, int left, int right);

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d %d", &A[i], &B[i], &C[i], &D[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sum1[i * n + j] = A[i] + B[j];
			sum2[i * n + j] = C[i] + D[j];
		}
	}

	sort(sum1, sum1 + n * n);
	sort(sum2, sum2 + n * n);
	
	for (int i = 0; i < n * n; i++) {
		int left = 0, right = n * n;
		while (left < right) {
			int mid = (left + right) / 2;
			if (-sum1[i] > sum2[mid])
				left = mid + 1;
			else
				right = mid;
		}
		int lower_bound = right;

		left = 0;
		right = n * n;
		while (left < right) {
			int mid = (left + right) / 2;
			if (-sum1[i] >= sum2[mid])
				left = mid + 1;
			else
				right = mid;
		}
		int upper_bound = right;

		result += (upper_bound - lower_bound);
	}
	
	/*
	for (int i = 0; i < n * n; i++) {
		result += binary_search(-sum1[i], 0, n * n - 1);
	}
	*/
	
	printf("%lld", result);
	return 0;
}


//반복된 재귀호출로 시간 초과 발생
long long int binary_search(int num, int left, int right) {
	//printf("%d %d %d %d\n", num, left, right, sum2[(left + right) / 2]);
	if (left <= right) {
		if (num < sum2[(left + right) / 2]) {
			return binary_search(num, left, (left + right) / 2 - 1);
		}
		else if (num > sum2[(left + right) / 2]) {
			return binary_search(num, (left + right) / 2 + 1, right);
		}
		else if (num == sum2[(left + right) / 2]) {
			int mid = (left + right) / 2;
			long long int num_result = 1;
			int temp = mid + 1;
			if (temp < n * n) {
				while (sum2[temp] == num) {
					temp++;
					num_result++;
					if (temp == n * n)
						break;
				}
			}

			temp = mid - 1;
			if (temp >= 0) {
				while (sum2[temp] == num) {
					temp--;
					num_result++;
					if (temp == -1)
						break;
				}
			}

			return num_result;
		}
	}
	else {
		return 0;
	}
}