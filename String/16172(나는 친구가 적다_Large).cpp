/*
��¥: 2020-02-11
�з�: String(KMP Algorithm)
TIP: �������� Substring Ž�� �˰���: O(nm)
	 KMP �˰���: O(n+m)
	 ã���� �ϴ� Substring�� ���� ���λ�� ���̻� ���̸� ��� �� ��,
	 �̹� Ž���ߴ� �κп� ���ؼ� �����ϸ� Ž�� �ӵ��� ����.
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