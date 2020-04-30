/*
��¥: 2020-04-27
�з�: �� ������, �����佺�׳׽��� ü
TIP:
1. �� ������
���ĵ� ���ҿ��� �ΰ��� �����͸� �¿�� �Դٰ����ϸ� O(n^2)�� O(n)����
low���� high���� �������� n���� ũ��? ==> low 1 ����
low���� hihg���� �������� n���� �۴�? ==> high 1 ����
2. �����佺�׳׽��� ü
�Ҽ��� ���� �� sqrt(�ִ� ��)������ �ݺ��Ͽ� ����ȭ ����
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