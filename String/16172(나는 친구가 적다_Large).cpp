/*
날짜: 2020-02-11
분류: String(KMP Algorithm)
TIP: 전통적인 Substring 탐색 알고리즘: O(nm)
	 KMP 알고리즘: O(n+m)
	 찾고자 하는 Substring의 공통 접두사와 접미사 길이를 계산 한 후,
	 이미 탐색했던 부분에 대해서 점프하며 탐색 속도를 높힘.
*/

#include <iostream>
#include <string>
#include <vector>
#define MAX 300000
#pragma warning (disable: 4996)

using namespace std;

string S, K, string_without_number;
bool result = false;

vector<int> fail_function();

int main() {
	cin >> S;
	cin >> K;
	
	for (int i = 0; i < S.size(); i++) {
		if (S[i] >= '0'&& S[i] <= '9')
			continue;
		string_without_number.push_back(S[i]);
	}
	
	vector<int> table;
	table = fail_function();

	int j = 0;
	for (int i = 0; i < string_without_number.size(); i++) {
		while (string_without_number[i] != K[j] && j > 0) {
			j = table[j - 1];
		}
		if (string_without_number[i] == K[j]) {
			if (j == K.size() - 1) {
				printf("1");
				return 0;
			}
			else {
				j++;
			}
		}
	}
	printf("0");
}

vector<int> fail_function() {
	vector<int> table((int)K.size(), 0);
	int j = 0;
	for (int i = 1; i < K.size(); i++) {
		while (K[i] != K[j] && j > 0) {
			j = table[j - 1];
		}
		if (K[i] == K[j]) {
			j++;
			table[i] = j;
		}
	}
	return table;
}