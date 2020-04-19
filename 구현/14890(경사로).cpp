/*
날짜: 2020-14-19
분류: 구현
TIP: 코드 깔끔하게 짤 수 있는가 생각해볼것
*/

#include <iostream>
#pragma warning (disable: 4996)

using namespace std;

int n, l;
int num, result = 0;
bool flag;
int arr[101][101] = { 0 };
int slope_row[101][101] = { 0 };
int slope_col[101][101] = { 0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		num = arr[i][0];
		flag = true;
		for (int j = 1; j < n; j++) {
			if (num == arr[i][j])
				continue;
			if (num - arr[i][j] == 1) {
				for (int k = 0; k < l; k++) {
					if (j + k >= n) {
						flag = false;
						break;
					}
					if (arr[i][j] != arr[i][j + k]) {
						flag = false;
						break;
					}
				}
			}
			else if (num - arr[i][j] == -1) {
				for (int k = 0; k < l; k++) {
					if (j - k - 1 < 0) {
						flag = false;
						break;
					}
					if (arr[i][j - 1] != arr[i][j - k - 1] || slope_row[i][j - k - 1] == 1) {
						flag = false;
					}
				}
			}
			else {
				flag = false;
			}

			if (flag) {
				int temp = num;
				num = arr[i][j];
				if (temp - arr[i][j] == 1) {
					for (int k = 0; k < l; k++) {
						slope_row[i][j + k] = 1;
					}
					j += (l - 1);
				}
				else {
					for (int k = 0; k < l; k++) {
						slope_row[i][j - k - 1] = 1;
					}
				}
			}
			else {
				break;
			}
		}
		if (flag) {
			result++;
		}
	}

	for (int j = 0; j < n; j++) {
		num = arr[0][j];
		flag = true;
		for (int i = 1; i < n; i++) {
			if (num == arr[i][j])
				continue;
			if (num - arr[i][j] == 1) {
				for (int k = 0; k < l; k++) {
					if (i + k >= n) {
						flag = false;
						break;
					}
					if (arr[i][j] != arr[i + k][j]) {
						flag = false;
						break;
					}
				}
			}
			else if (num - arr[i][j] == -1) {
				for (int k = 0; k < l; k++) {
					if (i - k - 1 < 0) {
						flag = false;
						break;
					}
					if (arr[i - 1][j] != arr[i - k - 1][j] || slope_col[i - k - 1][j] == 1) {
						flag = false;
					}
				}
			}
			else {
				flag = false;
			}

			if (flag) {
				int temp = num;
				num = arr[i][j];
				if (temp - arr[i][j] == 1) {
					for (int k = 0; k < l; k++) {
						slope_col[i + k][j] = 1;
					}
					i += (l - 1);
				}
				else {
					for (int k = 0; k < l; k++) {
						slope_col[i - k - 1][j] = 1;
					}
				}
			}
			else {
				break;
			}
		}
		if (flag) {
			result++;
		}
	}

	printf("%d", result);
	return 0;
}