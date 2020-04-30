#include <iostream>
#include <queue>
#include <stack>
#pragma warning (disable: 4996)

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	stack<int> bascket;
	queue<int> q[30];
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			if (board[i][j] != 0)
				q[j].push(board[i][j]);
		}
	}

	for (int i = 0; i < moves.size(); i++) {
		if (!q[moves[i] - 1].empty()) {
			int front = q[moves[i] - 1].front();
			q[moves[i] - 1].pop();
			if (bascket.size() == 0 || front != bascket.top()) {
				bascket.push(front);
			}
			else {
				bascket.pop();
				answer += 2;
			}
		}
	}
	return answer;
}