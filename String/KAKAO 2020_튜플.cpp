#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#pragma warning (disable: 4996)

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

vector<int> solution(string s);

int main() {
	vector<int> temp;
	temp = solution("{{25, 111},{111}}");
	for (int i = 0; i < temp.size(); i++) {
		printf("%d ", temp[i]);
	}
	printf("\n");
	return 0;
}

vector<int> solution(string s) {
	vector<int> answer;
	int tuple_num = 0;
	vector<int> tuple[501];
	vector<pair<int, int>> tuple_size;
	bool is_in = false;
	int temp = 0;
	for (int i = 1; i < s.length() - 1; i++) {
		if (s[i] == '}') {
			tuple[tuple_num].push_back(temp / 10);
			is_in = false;
		}
		else if (is_in) {
			if (s[i] == ',') {
				tuple[tuple_num].push_back(temp / 10);
				temp = 0;
				continue;
			}
			temp += (int)s[i] - 48;
			temp *= 10;
		}
		else if (s[i] == '{') {
			temp = 0;
			is_in = true;
			tuple_num++;
		}
	}

	for (int i = 1; i <= tuple_num; i++) {
		tuple_size.push_back({ i, tuple[i].size() });
	}

	sort(tuple_size.begin(), tuple_size.end(), cmp);

	set<int> se;
	for (int i = 0; i < tuple_size.size(); i++) {
		for (int j = 0; j <= i; j++) {
			auto it = se.find(tuple[tuple_size[i].first][j]);
			if (it == se.end()) {
				se.insert(tuple[tuple_size[i].first][j]);
				answer.push_back(tuple[tuple_size[i].first][j]);
				break;
			}
		}
	}
	return answer;
}