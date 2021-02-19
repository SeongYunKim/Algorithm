/*
 날짜: 2021-02-20
 분류: Math
 TIP: 나머지의 성질로 자료형 범위 및 시간 초과 해결
 */

#include <iostream>
#pragma warning(disable: 4996)

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        long long num = 0;
        long long digit = 1;
        while (true) {
            num = num * 10 + 1;
            if (num % n == 0) {
                cout << digit << "\n";
                break;
            }
            num %= n;
            digit++;
        }
    }
    return 0;
}
