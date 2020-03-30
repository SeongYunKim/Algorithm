/*
날짜: 2020-03-30
분류: BFS, 그래프 탐색
TIP: 
ios_base::sync_with_stdio(false); cin.tie(NULL);
없으면 입력 받을 때 시간초과
ios_base::sync_with_stdio(false); 
사용 시 scanf. printf를 섞어 사용하지 말 것!
key가 string이고 value가 vector<string>인 map 활용
*/

#include <iostream>
#include <queue>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#pragma warning (disable: 4996)

using namespace std;

int n;
vector<string> answer;
map<string, vector<string>> m;
map <string, int> visited;

void bfs();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		string s1, is, s2;
		cin >> s1 >> is >> s2;
		m[s1].push_back(s2);
	}
	bfs();
	sort(answer.begin(), answer.end());
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << "\n";
	}
}

void bfs() {
	queue<string> q;
	q.push("Baba");
	while (!q.empty()) {
		string cur = q.front();
		q.pop();
		for (int i = 0; i < m[cur].size(); i++) {
			if (visited[m[cur][i]] != 0)
				continue;
			q.push(m[cur][i]);
			answer.push_back(m[cur][i]);
			visited[m[cur][i]] = 1;
		}
	}
}