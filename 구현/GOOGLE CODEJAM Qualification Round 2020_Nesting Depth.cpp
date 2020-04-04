#include <iostream>
#include <string>
#pragma warning (disable: 4996)

using namespace std;

int t, opening;
string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	for (int a = 1; a <= t; a++) {
		cin >> s;
		cout << "Case #" << a << ": ";
		opening = 0;
		for (int i = 0; i < s.length(); i++) {
			int num = s[i] - '0';
			if (num > opening) {
				for (int j = opening; j < num; j++) {
					cout << '(';
				}
			}
			else if (num < opening) {
				for (int j = opening; j > num; j--) {
					cout << ')';
				}
			}
			opening = num;
			cout << s[i];
		}

		for (int i = 0; i < opening; i++) {
			cout << ')';
		}
		cout << '\n';
	}
	return 0;
}