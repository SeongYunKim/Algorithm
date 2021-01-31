/*
 * 날짜: 2021-02-01
 * 분류: Backtracking
 * TIP: 일단 실수를 너무 많이 했다.
 * 자주 실수 하는 부분 항상 주의 (for 종료 조건, 함수 반환형 등)
 * string 활용한 Backtracking (substr, erase)
 */

#include <iostream>
#include <string>

#pragma warning (disable: 4996)

using namespace std;

int N;

void dfs(int cnt, string s);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    dfs(1, "1");

    return 0;
}

void dfs(int cnt, string s) {
    if (cnt == N) {
        cout << s;
        exit(0);
    }
    for (int i = 0; i < 3; i++) {
        string newS = s + (char) (i + '1');
        bool isOkay = true;
        for (int compareLength = 1; compareLength <= (cnt + 1) / 2; compareLength++) {
            if (newS.substr(1 + cnt - compareLength, compareLength) ==
                newS.substr(1 + cnt - 2 * compareLength, compareLength)) {
                isOkay = false;
            }
        }
        if (isOkay)
            dfs(cnt + 1, newS);
    }
    s.erase(s.length() - 1);
}