/*
날짜: 2020-04-27
분류: 투 포인터, 에라토스테네스의 체
TIP:
1. 투 포인터
정렬된 원소에서 두개의 포인터를 좌우로 왔다갔다하며 O(n^2)을 O(n)으로
low부터 high까지 연속합이 n보다 크다? ==> low 1 증가
low부터 hihg까지 연속합이 n보다 작다? ==> high 1 증가
2. 에라토스테네스의 체
소수를 구할 때 sqrt(최대 수)까지만 반복하여 최적화 가능
*/

#include <iostream>
#include <cmath>
#include <vector>
#pragma warning (disable: 4996)

using namespace std;

int n, result = 0;
int num[4000001] = { 0 };
vector<int> v;

int main() {
	cin >> n;

	for (int i = 2; i <= sqrt(n); i++) {
		if (num[i] == 1)
			continue;
		for (int j = i * 2; j <= n; j += i) {
			num[j] = 1;
		}
	}

	for (int i = 2; i <= n; i++) {
		if (num[i] == 0)
			v.push_back(i);
	}

	int low = 0;
	int high = 0;
	int sum = 2;
	while(high < v.size()){
		if (sum > n) {
			if (low == v.size() - 1)
				break;
			sum -= v[low++];
		}
		else if (sum < n) {
			if (high == v.size() - 1)
				break;
			sum += v[++high];
		}
		else if (sum == n) {
			/*
			for (int i = low; i <= high; i++) {
				cout << v[i] << " ";
			}
			cout << endl;
			*/
			result++;
			if (high == v.size() - 1)
				break;
			sum += v[++high];
		}
	}
	cout << result;
}