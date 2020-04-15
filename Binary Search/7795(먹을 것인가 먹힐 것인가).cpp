/*
��¥: 2020-04-14
�з�: ����, Binary Search
TIP: lower_bound�� ũ�ų� ���� ���� ���� �ε��� ���ϱ�
*/

#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning (disable: 4996)

using namespace std;

int t, n, m;
int result = 0;
vector<int> a, b;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	while (t--) {
		int temp;
		result = 0;
		a.clear();
		b.clear();
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> temp;
			a.push_back(temp);
		}
		for (int i = 0; i < m; i++) {
			cin >> temp;
			b.push_back(temp);
		}
		sort(b.begin(), b.end());

		for (int i = 0; i < a.size(); i++) {
			result += (lower_bound(b.begin(), b.end(), a[i]) - b.begin());
		}

		printf("%d\n", result);
	}
}