/*
날짜: 2020-05-01
분류: Union-Find
TIP: Union시 각 Disjoin Set의 원소 수 업데이트
*/

#include <iostream>
#include <string>
#include <map>
#pragma warning (disable: 4996)

using namespace std;

int t, n, friend_num = 0;
string s1, s2;
map<string, int> m;
int root[100001] = { 0 };
int network_num[100001] = { 0 };

void init() {
	friend_num = 0;
	m.clear();
	for (int i = 0; i < 100001; i++) {
		root[i] = i;
		network_num[i] = 1;
	}
}

int func_find(int x) {
	if (root[x] == x)
		return x;
	else
		return root[x] = func_find(root[x]);
}

int func_union(int x, int y) {
	x = func_find(x);
	y = func_find(y);
	if (x != y) {
		root[x] = y;
		network_num[y] += network_num[x];
		network_num[x] = 1;
	}
	return network_num[y];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	while (t--) {
		init();
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> s1 >> s2;
			auto it = m.find(s1);
			if (it == m.end())
				m[s1] = friend_num++;
			it = m.find(s2);
			if (it == m.end())
				m[s2] = friend_num++;
			cout << func_union(m[s1], m[s2]) << "\n";
		}
	}
	return 0;
}