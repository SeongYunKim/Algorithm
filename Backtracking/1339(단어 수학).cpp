/*
날짜: 2020-03-31
분류: DFS, Backtracking
TIP:
vector.size()는 unsigned int형을 반환
vector.size()가 n일 때
n - vector.size() -1은 자료형 오버플로우로 1이 아닌 '예상하지 못한 값'
애매할때는 (int)vector.size()로 형변환을 꼭 해주자
*/

#include <iostream>
#include <string>
#include <map>
#include <vector>
#pragma warning (disable: 4996)

using namespace std;

int n;
string s[10];
map<char, int[8]> m;
vector<char> char_v;
vector<int> int_v;
int visited[10] = { 0 };
int answer = 0;

void dfs(int cnt);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		for (int j = 0; j < s[i].length(); j++) {
			auto it = m.find(s[i][j]);
			if (it == m.end()) {
				char_v.push_back(s[i][j]);
			}
			m[s[i][j]][s[i].length() - j - 1]++;
		}
	}
	dfs(0);
	printf("%u", (unsigned int)10 - char_v.size() - 1);
	printf("%d", answer);
}

void dfs(int cnt) {
	if (cnt == char_v.size()) {
		int result = 0;
		for (int i = 0; i < char_v.size(); i++) {
			//printf("%d ", int_v[i]);
			int temp = 0;
			for (int j = 7; j >= 0; j--) {
				temp *= 10;
				temp += (m[char_v[i]][j] * int_v[i]);
			}
			result += temp;
		}
		if (result > answer) {
			answer = result;
		}
		//printf("\n");
		return;
	}
	for (int i = 9; i >= 10 - (int)char_v.size(); i--) {
		if (visited[i] == 0) {
			visited[i] = 1;
			int_v.push_back(i);
			dfs(cnt + 1);
			int_v.pop_back();
			visited[i] = 0;
		}
	}
}