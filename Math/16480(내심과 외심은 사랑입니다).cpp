#include <iostream>
#pragma warning (disable: 4996)

using namespace std;

long long int out_R, in_r;

int main() {
	long long int result;
	scanf("%lld %lld", &out_R, &in_r);
	result = (out_R * out_R) - (2 * out_R * in_r);
	printf("%lld", result);
}