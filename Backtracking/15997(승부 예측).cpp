#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#pragma warning (disable: 4996)

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.first > b.first;
}

string team[4];
string match[6][2];
double prob[6][3];
double result[4] = { 0 };
int point[3] = { 3, 1, 0 };
vector<int> v;
map<string, int> m;

void backtracking(int cnt);

int main() {
	cin >> team[0] >> team[1] >> team[2] >> team[3];
	for (int i = 0; i < 4; i++) {
		m.insert({ team[i], i });
	}
	for (int i = 0; i < 6; i++) {
		cin >> match[i][0] >> match[i][1] >> prob[i][0] >> prob[i][1] >> prob[i][2];
	}

	backtracking(0);

	for (int i = 0; i < 4; i++) {
		printf("%.10lf\n", result[i]);
	}
	return 0;
}

void backtracking(int cnt) {
	int team_point[4] = { 0 };
	vector<pair<int, int>> temp_v;
	double basic_prob = 1;
	double temp_result[4] = { 0 };
	if (cnt == 6) {
		for (int i = 0; i < 6; i++) {
			if (v[i] == 3) {
				team_point[m[match[i][0]]] += 3;
				basic_prob *= prob[i][0];
			}
			else if (v[i] == 1) {
				team_point[m[match[i][0]]] += 1;
				team_point[m[match[i][1]]] += 1;
				basic_prob *= prob[i][1];
			}
			else if (v[i] == 0) {
				team_point[m[match[i][1]]] += 3;
				basic_prob *= prob[i][2];
			}
		}

		int cnt = 2;
		for (int i = 0; i < 4; i++) {
			temp_v.push_back({ team_point[i], i });
		}
		while (cnt > 0) {
			int num = 0;
			sort(temp_v.begin(), temp_v.end(), cmp);
			int first_score = temp_v[0].first;
			for (int i = 0; i < 4; i++) {
				if (first_score == temp_v[i].first) {
					num++;
				}
			}
			for (int i = 0; i < num; i++) {
				result[temp_v[i].second] += basic_prob / num;
				temp_v[i].first = -1;
			}
			cnt -= num;
		}

		/*
		for (int i = 0; i < 4; i++) {
			temp_v.push_back({ team_point[i], i });
		}

		sort(temp_v.begin(), temp_v.end());

		if (temp_v[1].first == temp_v[2].first) {
			if (temp_v[2].first == temp_v[3].first) {
				if (temp_v[0].first == temp_v[1].first) {
					result[0] += (basic_prob / 4);
					result[1] += (basic_prob / 4);
					result[2] += (basic_prob / 4);
					result[3] += (basic_prob / 4);
				}
				else {
					result[temp_v[1].second] += (basic_prob / 3);
					result[temp_v[2].second] += (basic_prob / 3);
					result[temp_v[3].second] += (basic_prob / 3);
				}
			}
			else if (temp_v[0].first == temp_v[1].first) {
				result[temp_v[0].second] += (basic_prob / 3);
				result[temp_v[1].second] += (basic_prob / 3);
				result[temp_v[2].second] += (basic_prob / 3);
				result[temp_v[3].second] += basic_prob;
			}
			else {
				result[temp_v[1].second] += (basic_prob / 2);
				result[temp_v[2].second] += (basic_prob / 2);
				result[temp_v[3].second] += basic_prob;
			}
		}
		else {
			result[temp_v[2].second] += basic_prob;
			result[temp_v[3].second] += basic_prob;
		}
		*/

		return;
	}

	for (int i = 0; i < 3; i++) {
		v.push_back(point[i]);
		backtracking(cnt + 1);
		v.pop_back();
	}
}