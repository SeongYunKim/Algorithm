#include <string>

using namespace std;

int solution(string s) {
	int answer = 1e9;
	int temp[502] = { 0 };
	int sl = s.length();
	temp[0] = sl;
	for (int i = 1; i <= sl / 2; i++) {
		//printf("\n%d: ", i);
		int index = 0;
		int duplicate = 1;
		while (index <= sl - (sl % i) - i) {
			bool is_same = true;
			for (int j = 0; j < i; j++) {
				if (s[index + j] != s[index + j + i]) {
					if (duplicate > 1) {
						temp[i] += (1 + i);
						/*
						printf("%d", duplicate);
						for(int a = 0; a < i; a++){
							printf("%c", s[index + a]);
						}
						*/
					}
					else {
						temp[i] += i;
						/*
						for(int a = 0; a < i; a++){
							printf("%c", s[index + a]);
						}
						*/
					}
					is_same = false;
					duplicate = 1;
					break;
				}
			}
			if (is_same) {
				duplicate++;
			}
			index += i;
		}
		for (int j = index; j < sl; j++) {
			temp[i]++;
			//printf("%c", s[j]);
		}
	}

	for (int i = 0; i <= sl / 2; i++) {
		if (temp[i] < answer)
			answer = temp[i];
	}
	return answer;
}