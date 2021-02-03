/*
 * 날짜: 2021-02-03
 * 분류: DFS
 * TIP: index를 cnt와 함께 DFS 인자로 넘기기
 */

#include <iostream>
#include <string>

#pragma warning (disable: 4996)

using namespace std;

int N, K;
int result = 0;
bool visited[26] = {0};
char occupiedAlphabet[5] = {'a', 'n', 't', 'i', 'c'};
string s[50];

void dfs(int cnt, int index) {
    if (cnt == K - 5) {
        int completeNum = 0;
        for (int i = 0; i < N; i++) {
            bool canComplete = true;
            for (int j = 0; j < s[i].length(); j++) {
                if (!visited[s[i][j] - 'a']) {
                    canComplete = false;
                    break;
                }
            }
            if (canComplete)
                completeNum++;
        }
        if (completeNum > result) {
            result = completeNum;
        }
    }

    for (int i = index; i < 26; i++) {
        if (!visited[i]) {
            visited[i] = true;
            dfs(cnt + 1, i + 1);
            visited[i] = false;
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 5; i++) {
        visited[occupiedAlphabet[i] - 'a'] = true;
    }

    cin >> N >> K;

    if (K < 5) {
        cout << 0;
        return 0;
    }

    for (int i = 0; i < N; i++) {
        cin >> s[i];
        for (int j = 0; j < s[i].length(); j++) {
            if (s[i][j] == 'a' || s[i][j] == 'n' || s[i][j] == 't' || s[i][j] == 'i' || s[i][j] == 'c') {
                s[i].erase(j, 1);
                j--;
            }
        }
    }

    dfs(0, 0);
    cout << result;

    return 0;
}