/*
��¥: 2020-04-24
�з�: ���ڿ�, ����
TIP: ���� ���������� ������ �ڵ������� ��
���Ͽ� ���� ���� ���� �� ��ġ�� �������� ���� ��,
���� �� �ڵ��� erase
*/

#include <iostream>
#include <map>
#include <vector>
#pragma warning (disable: 4996)

using namespace std;

int n, result = 0;
map<string, int> m;
vector<int> before, after;

int main() {
	string s;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		m[s] = i;
		before.push_back(i);
	}

	for (int i = 0; i < n; i++) {
		cin >> s;
		after.push_back(m[s]);
	}

	for (int i = n - 1; i >= 0; i--) {
		if (before[i] != after[i]) {
			result++;
			for (int j = 0; j < after.size(); j++) {
				if (before[i] == after[j]) {
					after.erase(after.begin() + j);
					break;
				}
			}
		}
	}
	cout << result;
	return 0;
}