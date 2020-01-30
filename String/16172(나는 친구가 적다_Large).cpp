#include <iostream>
#include <string>
#pragma warning (disable: 4996)

using namespace std;

string S, K;

int main() {
	cin >> S;
	cin >> K;
	int j = 0;
	bool result = false;
	for (int i = 0; i < S.length(); i++) {
		if (S[i] == K[0]) {
			result = true;
			int k = 0;
			for (int j = 0; j < K.length(); j++) {
				if (S[i + k] >= '0' && S[i + k] <= '9') {
					j--;
					k++;
					continue;
				}

				if (S[i + k] != K[j]) {
					result = false;
					break;
				}
				k++;
			}
		}
		if (result) {
			break;
		}
	}
	if (result) {
		printf("1");
	}
	else {
		printf("0");
	}
	return 0;
}