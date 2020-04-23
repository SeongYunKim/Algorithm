/*
날짜: 2020-04-24
분류: 문자열, 구현
TIP: 가장 마지막으로 진입한 자동차부터 비교
비교하여 진입 전과 진입 후 위치가 동일하지 않을 시,
진입 후 자동차 erase
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