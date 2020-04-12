/*
날짜: 2020-04-13
분류: 문자열
TIP: 각 문자열을 * 기준으로 나눈 후 첫번째와 마지막 부분 문자열의 일치여부 검사
가운데 문자열은 순서 상관 없이 concat
*/

#include <iostream>
#include <string>
#include <vector>
#pragma warning (disable: 4996)

using namespace std;

int t, n;
string s;
vector<string> v, s_start, s_end, s_middle;
int start_max = 0, end_max = 0, start_max_index = -1, end_max_index = -1;

void init() {
	v.clear();
	s_start.clear();
	s_end.clear();
	s_middle.clear();
	start_max = 0;
	end_max = 0;
	start_max_index = -1;
	end_max_index = -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	for (int a = 1; a <= t; a++) {
		init();
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> s;
			v.push_back(s);
		}
		for (int i = 0; i < n; i++) {
			int index = 0;
			string temp = "";
			while (v[i][index] != '*') {
				temp += v[i][index];
				index++;
			}
			if (temp.compare("") != 0) {
				s_start.push_back(temp);
			}
			if (temp.length() > start_max) {
				start_max = temp.length();
				start_max_index = s_start.size() - 1;
			}

			int temp_index = index + 1;
			temp = "";
			for (; temp_index < v[i].length(); temp_index++) {
				if (v[i][temp_index] == '*') {
					if (temp.compare("") != 0) {
						s_middle.push_back(temp);
					}
					temp = "";
				}
				else {
					temp += v[i][temp_index];
				}
			}

			index = v[i].length() - 1;
			temp = "";
			while (v[i][index] != '*') {
				temp += v[i][index];
				index--;
			}
			if (temp.compare("") != 0) {
				s_end.push_back(temp);
			}
			if (temp.length() > end_max) {
				end_max = temp.length();
				end_max_index = s_end.size() - 1;
			}
		}

		bool flag = true;
		for (int a = 0; a < s_start.size(); a++) {
			for (int i = 0; i < s_start[a].length(); i++) {
				if (s_start[a][i] != s_start[start_max_index][i]) {
					flag = false;
					break;
				}
			}
			if (!flag)
				break;
		}

		for (int a = 0; a < s_end.size(); a++) {
			for (int i = 0; i < s_end[a].length(); i++) {
				if (s_end[a][i] != s_end[end_max_index][i]) {
					flag = false;
					break;
				}
			}
			if (!flag)
				break;
		}

		cout << "Case #" << a << ": ";
		if (flag) {
			if (start_max_index != -1) {
				for (int i = 0; i < s_start[start_max_index].length(); i++) {
					cout << s_start[start_max_index][i];
				}
			}


			for (int i = 0; i < s_middle.size(); i++) {
				for (int j = 0; j < s_middle[i].length(); j++) {
					cout << s_middle[i][j];
				}
			}

			if (end_max_index != -1) {
				for (int i = 0; i < s_end[end_max_index].length(); i++) {
					cout << s_end[end_max_index][s_end[end_max_index].length() - i - 1];
				}
			}
		}
		else {
			cout << "*";
		}
		cout << endl;
	}
	return 0;
}