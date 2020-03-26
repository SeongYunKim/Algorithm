#include <iostream>
#define SCHOOL_MAX 200001
#define STUDENT_MAX 2000001
#pragma warning (disable: 4996)

using namespace std;

int n;
//index 학교의 학생수
int student[SCHOOL_MAX] = { 0 };
//학생수가 index인 학교의 수
int team[STUDENT_MAX] = { 0 };
long long int result[STUDENT_MAX] = { 0 };
long long int max_result = 0;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &student[i]);
		team[student[i]]++;
		/*
		for (int j = 1; j <= student[i]; j++) {
			if (student[i] % j == 0) {
				team[j] += j;
			}
		}
		*/
	}

	for (int i = 1; i < STUDENT_MAX; i++) {
		for (int j = i; j < STUDENT_MAX; j += i) {
			result[i] += team[j];
		}
	}

	for (int i = 1; i < STUDENT_MAX; i++) {
		if (max_result < result[i] * i && result[i] > 1) {
			max_result = result[i] * i;
		}
	}

	printf("%lld", max_result);
	return 0;
}
