/*
날짜: 2020-04-03
분류: Binary Search, 효율성
TIP: Binary Search를 통해 O(NM)에서 O(NlogM)으로
N = 디딤돌 개수, M = 디딤돌 숫자의 최대값
O(N)으로도 해결 가능하다는데 고민해 볼것!
*/

#include <iostream>
#include <vector>
#pragma warning (disable: 4996)

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

int solution(vector<int> stones, int k);

int main() {
	vector<int> stones;
	stones.push_back(2);
	stones.push_back(4);
	stones.push_back(5);
	stones.push_back(3);
	stones.push_back(2);
	stones.push_back(1);
	stones.push_back(4);
	stones.push_back(2);
	stones.push_back(5);
	stones.push_back(1);
	printf("%d", solution(stones, 3));
	return 0;
}

int solution(vector<int> stones, int k) {
	int answer;
	int max = 0;
	for (int i = 0; i < stones.size(); i++) {
		if (max < stones[i])
			max = stones[i];
	}

	int mid, left = 0, right = max;
	while (left < right) {
		mid = (left + right) / 2;
		int step = 0;
		int max_step = 0;
		for (int i = 0; i < stones.size(); i++) {
			//mid번째 사람까지는 징검다리를 건넜다고 가정
			if (stones[i] - mid > 0) {
				step = 0;
				continue;
			}
			step++;
			if (max_step < step) {
				//max_step: mid번째 사람이 건넌 후 연속된 빈칸 중 가장 긴 길이
				max_step = step;
			}
		}
		//mid + 1번째 사람이 징검다리를 건널 수 있는가?
		if (max_step >= k) {
			//건널 수 없다 --> 가능한 정답의 max를 mid로
			right = mid;
		}
		else if (max_step < k) {
			//건널 수 있다 --> 가능한 정답의 min을 mid + 1로
			left = mid + 1;
		}
	}
	answer = right;
	return answer;
}