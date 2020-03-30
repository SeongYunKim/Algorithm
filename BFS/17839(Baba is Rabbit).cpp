/*
��¥: 2020-03-30
�з�: BFS, �׷��� Ž��
TIP: 
ios_base::sync_with_stdio(false); cin.tie(NULL);
������ �Է� ���� �� �ð��ʰ�
ios_base::sync_with_stdio(false); 
��� �� scanf. printf�� ���� ������� �� ��!
key�� string�̰� value�� vector<string>�� map Ȱ��
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