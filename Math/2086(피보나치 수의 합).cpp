/*
날짜: 2020-04-29
분류: 수학, 피보나치 수
TIP: 행렬 곱셈을 활용하여 피보나치 수를 O(logn)에 구하기
[Fn+1 Fn| = [1 1|^n
|Fn Fn-1]	|1 0]
이때 행렬의 거듭제곱은 O(logn)에 구할 수 있음
=> n이 2의 거듭제곱(1, 2, 4, 8...)일때만 계산 후
이들의 조합으로 n 만들기
ex) A^19 = A^16 * A^2 * A^1
*/

#include <iostream>
#include <vector>
#define DIV 1000000000
#pragma warning (disable: 4996)

using namespace std;

long long a, b;
vector<pair<long long, long long**>> v;

long long** mult(long long **a, long long **b);

int main() {
	cin >> a >> b;
	long long** matrix = new long long* [2];
	for (int i = 0; i < 2; i++)
		matrix[i] = new long long[2];
	matrix[0][0] = 1, matrix[0][1] = 1, matrix[1][0] = 1, matrix[1][1] = 0;
	v.push_back({ 0, matrix });
	unsigned long long  n = 1;
	while (n <= b + 2) {
		matrix = mult(matrix, matrix);
		v.push_back({ n, matrix });
		n *= 2;
	}

	long long tempA = a + 1;
	long long tempB = b + 2;
	long long sumA, sumB;
	long long i = 0;
	matrix[0][0] = 1, matrix[0][1] = 0, matrix[1][0] = 0, matrix[1][1] = 1;
	while (tempA != 0) {
		if (tempA % 2 == 1) {
			matrix = mult(matrix, v[i].second);
		}
		tempA /= 2;
		i++;
	}
	sumA = matrix[1][0];
	i = 0;
	matrix[0][0] = 1, matrix[0][1] = 0, matrix[1][0] = 0, matrix[1][1] = 1;
	while (tempB != 0) {
		if (tempB % 2 == 1) {
			matrix = mult(matrix, v[i].second);
		}
		tempB /= 2;
		i++;
	}
	sumB = matrix[1][0];
	//cout << sumA << "/" << sumB << endl;
	long long result = sumB - sumA;
	if (result < 0)
		result = result + DIV;
	cout << result;
	return 0;
}

long long** mult(long long **a, long long **b) {
	long long** multResult = new long long* [2];
	for (int i = 0; i < 2; i++) 
		multResult[i] = new long long [2];
	multResult[0][0] = (((a[0][0] * b[0][0]) % DIV) + ((a[0][1] * b[1][0]) % DIV)) % DIV;
	multResult[0][1] = (((a[0][0] * b[0][1]) % DIV) + ((a[0][1] * b[1][1]) % DIV)) % DIV;
	multResult[1][0] = (((a[1][0] * b[0][0]) % DIV) + ((a[1][1] * b[1][0]) % DIV)) % DIV;
	multResult[1][1] = (((a[1][0] * b[0][1]) % DIV) + ((a[1][1] * b[1][1]) % DIV)) % DIV;
	return multResult;
}