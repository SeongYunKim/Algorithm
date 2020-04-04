#include <iostream>
#include <set>
#pragma warning (disable: 4996)

using namespace std;

int t, n;
int k, r, c;
int arr[101][101] = { 0 };
set<int> s;

int main() {
	scanf("%d", &t);
	for(int a = 1; a <= t; a++) {
		k = 0;
		r = 0;
		c = 0;

		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			s.clear();
			for (int j = 0; j < n; j++) {
				scanf("%d", &arr[i][j]);
				if (i == j) {
					k += arr[i][j];
				}
			}
		}

		for (int i = 0; i < n; i++) {
			s.clear();
			for (int j = 0; j < n; j++) {
				auto it = s.find(arr[i][j]);
				if (it == s.end()) {
					s.insert(arr[i][j]);
				}
				else {
					r++;
					break;
				}
			}
		}

		for (int i = 0; i < n; i++) {
			s.clear();
			for (int j = 0; j < n; j++) {
				auto it = s.find(arr[j][i]);
				if (it == s.end()) {
					s.insert(arr[j][i]);
				}
				else {
					c++;
					break;
				}
			}
		}
		printf("Case #%d: %d %d %d\n", a, k, r, c);
	}
}