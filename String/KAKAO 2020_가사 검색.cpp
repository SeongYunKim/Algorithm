/*
날짜: 2020-04-22
분류: String, Trie
TIP: words를 순방향, 역방향으로 저장한 각각의 Trie 생성
+ words의 길이 별로 각각의 Trie 생성
+ 각 Trie 노드에 sub-Trie의 개수를 변수 num에 저장
Trie 자료구조 정리: https://github.com/SeongYunKim/TIL/blob/master/Algorithm/Trie.md

string을 const char*로 변환하여 실행 시간 단축
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#pragma warning (disable: 4996)

using namespace std;

typedef struct trie {
	trie* next[26];
	int num = 0;

	trie() {
		memset(next, 0, sizeof(next));
	}

	void insert(const char* s) {
		num++;
		if (*s != '\0') {
			int char_to_int = *s - 'a';
			if (next[char_to_int] == NULL)
				next[char_to_int] = new trie();
			next[char_to_int]->insert(s + 1);
		}
	}

	int search(const char* s) {
		if (*s == '\0') {
			return num;
		}
		else {
			int char_to_int = *s - 'a';
			if (next[char_to_int] == NULL)
				return 0;
			else
				return next[char_to_int]->search(s + 1);
		}
	}
}trie;

trie root_front[10001], root_back[10001];

vector<int> solution(vector<string> words, vector<string> queries) {
	vector<int> answer;

	for (int i = 0; i < words.size(); i++) {
		const char* words_to_char = words[i].c_str();
		string reverse_string = words[i];
		reverse(reverse_string.begin(), reverse_string.end());
		const char* reverse_words_to_char = reverse_string.c_str();
		root_front[words[i].size()].insert(words_to_char);
		root_back[words[i].size()].insert(reverse_words_to_char);
	}

	for (int i = 0; i < queries.size(); i++) {
		int j = 0;
		if (queries[i][queries[i].size() - 1] == '?') {
			while (queries[i][j] != '?') {
				j++;
			}
			string sub_str = queries[i].substr(0, j);
			answer.push_back(root_front[queries[i].size()].search(sub_str.c_str()));
		}
		else if (queries[i][0] == '?') {
			while (queries[i][queries[i].size() - 1 - j] != '?') {
				j++;
			}
			string sub_str = queries[i].substr(queries[i].size() - j, j);
			reverse(sub_str.begin(), sub_str.end());
			answer.push_back(root_back[queries[i].size()].search(sub_str.c_str()));
		}
	}

	return answer;
}

int main() {
	vector<string> words, queries;
	vector<int> answer;
	words.push_back("frodo");
	words.push_back("front");
	words.push_back("frost");
	words.push_back("frozen");
	words.push_back("frame");
	words.push_back("kakao");
	queries.push_back("fro??");
	queries.push_back("????t");
	queries.push_back("????o");
	queries.push_back("fr???");
	queries.push_back("fro???");
	queries.push_back("pro?");
	queries.push_back("?????");
	queries.push_back("?");
	answer = solution(words, queries);
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}
	return 0;
}