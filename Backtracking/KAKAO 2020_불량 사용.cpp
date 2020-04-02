/*
날짜: 2020-04-02
분류: String, Backtracking
TIP: Backtracking으로 완전 탐색한 후
bitset를 활용하여 원소 순서를 바꿨을 때 일치하는 조합을 제외
통과는 했는데 뭔가 찝집,,,더 좋은 방법 있으면 알려주세요ㅎㅎ

bitset<8> bits;			//비트셋 최대 크기 설정
bits.reset();			//모든 비트 0으로 설정
bits.set(index, bool);	//index번째 bit를 bool로 설정
bits.to_string();		//비트셋을 문자열로 변환
*/

#include <vector>
#include <string>
#include <set>
#include <bitset>
#pragma warning (disable: 4996)

using namespace std;

int result = 0;
int visited[10] = { 0 };
vector<int> id[10];
vector<int> v;
set<string> ss;

int solution(vector<string> user_id, vector<string> banned_id);

int main() {
	int main_result;
	vector<string> user_id;
	vector<string> banned_id;
	user_id.push_back("frodo");
	user_id.push_back("fradi");
	user_id.push_back("crodo");
	user_id.push_back("abc123");
	user_id.push_back("frodoc");
	banned_id.push_back("fr*d*");
	//banned_id.push_back("abc1**");
	//banned_id.push_back("*rodo");
	banned_id.push_back("*rodo");
	banned_id.push_back("******");
	banned_id.push_back("******");
	main_result = solution(user_id, banned_id);
	printf("%d", main_result);
	return 0;
}

void backtracking(int cnt, int banned_id_size) {
	if (cnt == banned_id_size) {
		bitset<8> bits;
		bits.reset();
		for (int i = 0; i < v.size(); i++) {
			bits.set(v[i], true);
			//printf("%d ", v[i]);
		}

		string bit_string = bits.to_string();
		auto it = ss.find(bit_string);
		if (it == ss.end()) {
			ss.insert(bit_string);
			result++;
		}
		return;
	}

	for (int i = 0; i < id[cnt].size(); i++) {
		if (visited[id[cnt][i]] == 0){
			v.push_back(id[cnt][i]);
			visited[id[cnt][i]] = 1;
			backtracking(cnt + 1, banned_id_size);
			visited[id[cnt][i]] = 0;
			v.pop_back();
		}
	}
}


int solution(vector<string> user_id, vector<string> banned_id) {
	int answer = 0;

	for (int i = 0; i < banned_id.size(); i++) {
		for (int j = 0; j < user_id.size(); j++) {
			bool is_same = true;
			if (user_id[j].length() != banned_id[i].length()) {
				is_same = false;
				continue;
			}
			for (int k = 0; k < banned_id.size(); k++) {
				if (banned_id[i][k] == '*')
					continue;
				if (banned_id[i][k] != user_id[j][k]) {
					is_same = false;
					break;
				}
			}

			if (is_same) {
				id[i].push_back(j);
			}
		}
	}

	backtracking(0, banned_id.size());
	answer = result;
	return answer;
}