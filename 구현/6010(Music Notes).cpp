#include <iostream>
#pragma warning (disable: 4996)

using namespace std;

int n, q;
int arr[50001] = { 0 };

int main() {
	scanf("%d %d", &n, &q);
	int time, question;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &time);
		arr[i] = arr[i - 1] + time;
	}
	for (int i = 0; i < q; i++) {
		scanf("%d", &question);
		for (int i = 1; i <= n; i++) {
			if (arr[i] > question) {
				printf("%d\n", i);
				break;
			}
		}
	}
	return 0;
}