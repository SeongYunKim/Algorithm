/*
날짜: 2020-03-30
분류: 수학, 큰 수 연산
TIP: 알고리즘 자체는 어렵지 않지만 
long long 자료형으로는 36^50을 처리할 수 없으므로,
직접 36진수 덧셈, 곱셈, 대소비교 등을 구현해줘야 하는 문제(토 할뻔)
*/

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#pragma warning (disable: 4996)

using namespace std;

int n, k;
string s[50];
map<char, int> m0;
map<int, char> m1;

//36진수 i가 j번째 자리수에 몇번 나오는가를 저장하는 배열
int digit[36][52] = { 0 };
//36진수 i를 'Z'로 바꿨을 때 얼마를 이득볼 수 있는가?(16진수로)
char multiple_result[36][52] = { 0 };
int index[36] = { 0 };

void multiple(int num);
bool cmp(int a, int b);

int main() {
	for (int i = 0; i < 10; i++) {
		m0[i + 48] = i;
		m1[i] = i + 48;
	}
	for (int i = 10; i < 36; i++) {
		m0[i + 55] = i;
		m1[i] = i + 55;
	}
	for (int i = 0; i < 36; i++) {
		index[i] = i;
	}
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		for (int j = 0; j < s[i].length(); j++) {
			digit[m0[s[i][j]]][s[i].length() - j - 1] ++;
		}
	}

	for (int i = 0; i < 36; i++) {
		multiple(i);
	}

	sort(index, index + 36, cmp);

	scanf("%d", &k);
	
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < 52; j++) {
			digit[multiple_result[index[i]][j]][j]++;
		}
	}

	vector<char> answer;
	int carry = 0;
	for (int i = 0; i < 52; i++) {
		int temp = carry;
		for (int j = 0; j < 36; j++) {
			temp += digit[j][i] * j;
		}
		answer.push_back(m1[temp % 36]);
		carry = temp / 36;
	}

	bool can_print = false;
	for (int i = answer.size() - 1; i >= 0; i--) {
		if (answer[i] != '0')
			can_print = true;
		if (can_print) {
			printf("%c", answer[i]);
		}		
	}

	if (!can_print) {
		printf("0");
	}
	return 0;
}

void multiple(int num) {
	int carry = 0;
	for (int i = 0; i < 52; i++) {
		int temp = (digit[num][i] * (35 - num) + carry) / 36;
		multiple_result[num][i] = (digit[num][i] * (35 - num) + carry) % 36;
		carry = temp;
	}
}

bool cmp(int a, int b) {
	for (int i = 51; i >= 0; i--) {
		if (multiple_result[a][i] > multiple_result[b][i])
			return true;
		if (multiple_result[a][i] < multiple_result[b][i])
			return false;
	}
	return false;
}