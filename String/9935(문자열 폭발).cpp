/*
��¥: 2020-01-16
�з�:String
TIP: O(N)�� Ǯ��� �ð��ʰ�X, 
     ��ź�� ������ ���� üũ�ϴ� ����: ��ź ���� �� ���� �������� ���� ����
*/

#include <iostream>
#include <string>
#pragma warning (disable: 4996)

using namespace std;

string s, bomb;
char result[1000001];

int main() {
	cin >> s >> bomb;
	int index = 0;
	for (int i = 0; i < s.length(); i++) {
		result[index++] = s[i];
		bool is_bomb = true;
		if (s[i] == bomb[bomb.length() - 1]) {
			bool is_bomb = true;
			for (int j = index - bomb.length(); j < index; j++) {
				if (result[j] != bomb[j - index + bomb.length()]) {
					is_bomb = false;
					break;
				}
			}
			if (is_bomb) {
				index -= bomb.length();
			}
		}

	}
	if (index == 0) {
		printf("FRULA");
	}
	else {
		for (int i = 0; i < index; i++) {
			printf("%c", result[i]);
		}
	}
	return 0;
}