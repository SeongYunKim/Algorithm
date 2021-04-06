/*
 * 날짜: 2021-04-04
 * 분류: Backtracking, Brute-force
 * TIP: 구현력 + Backtracking, 초기화가 필요한 변수는 지역 변수로(실수 방지)
 * 비트마스크 + 룩업테이블을 활용한 풀이: https://eine.tistory.com/entry/%EB%B0%B1%EC%A4%80-17825%EB%B2%88-%EC%A3%BC%EC%82%AC%EC%9C%84-%EC%9C%B7%EB%86%80%EC%9D%B4-%EB%AC%B8%EC%A0%9C-%ED%92%80%EC%9D%B4
 */

#include <iostream>
#include <map>

#pragma warning (disable: 4996)

using namespace std;
int dice[10] = {0};
int combination[10] = {0};
int maxScore = 0;
int boardScore[33] = {0};
int nextBoardPosition[32] = {0};
map<int, int> specialNextBoardPosition;

void dfs(int cnt) {
    if (cnt == 10) {
        // 실수 포인트. currentPosition을 초기화 해주지 않았음 => 초기화가 필요한 변수는 전역변수로 선언하지 말 것!
        int currentPosition[4] = {0};
        bool occupation[33] = {false};
        for (int i = 0; i < 4; i++)
            currentPosition[i] = 0;
        int score = 0;
        for (int i = 0; i < 10; i++) {
            int beforeMovePosition = currentPosition[combination[i]];
            int afterMovePosition = beforeMovePosition;
            if (beforeMovePosition == 32)
                return;
            occupation[beforeMovePosition] = false;
            for (int j = 0; j < dice[i]; j++) {
                // 파란색 칸에서 이동을 시작할 경우
                if (j == 0 && specialNextBoardPosition.find(afterMovePosition) != specialNextBoardPosition.end())
                    afterMovePosition = specialNextBoardPosition[afterMovePosition];
                else
                    afterMovePosition = nextBoardPosition[afterMovePosition];
                if (afterMovePosition == 32)
                    break;
            }
            // 이동 마친 칸에 다른 말이 있으면 말을 고를 수 없음(도착 칸 제외)
            if (afterMovePosition != 32) {
                if (occupation[afterMovePosition]) {
                    occupation[beforeMovePosition] = true;
                    return;
                }
            }
            currentPosition[combination[i]] = afterMovePosition;
            occupation[afterMovePosition] = true;
            score += boardScore[currentPosition[combination[i]]];
        }
        if (score > maxScore)
            maxScore = score;
        return;
    }
    for (int i = 0; i < 4; i++) {
        combination[cnt] = i;
        dfs(cnt + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 0; i < 10; i++)
        cin >> dice[i];
    for (int i = 1; i <= 20; i++)
        boardScore[i] = 2 * i;
    for (int i = 0; i <= 31; i++)
        nextBoardPosition[i] = i + 1;
    nextBoardPosition[20] = 32;
    boardScore[21] = 13;
    boardScore[22] = 16;
    boardScore[23] = 19;
    nextBoardPosition[23] = 29;
    boardScore[24] = 22;
    boardScore[25] = 24;
    nextBoardPosition[25] = 29;
    boardScore[26] = 28;
    boardScore[27] = 27;
    boardScore[28] = 26;
    boardScore[29] = 25;
    boardScore[30] = 30;
    boardScore[31] = 35;
    nextBoardPosition[31] = 20;
    specialNextBoardPosition[5] = 21;
    specialNextBoardPosition[10] = 24;
    specialNextBoardPosition[15] = 26;
    dfs(0);
    cout << maxScore;
    return 0;
}
