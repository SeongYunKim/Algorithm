/*
��¥: 2020-04-03
�з�: Binary Search, ȿ����
TIP: Binary Search�� ���� O(NM)���� O(NlogM)����
N = ����� ����, M = ����� ������ �ִ밪
O(N)���ε� �ذ� �����ϴٴµ� ����� ����!
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
			//mid��° ��������� ¡�˴ٸ��� �ǳԴٰ� ����
			if (stones[i] - mid > 0) {
				step = 0;
				continue;
			}
			step++;
			if (max_step < step) {
				//max_step: mid��° ����� �ǳ� �� ���ӵ� ��ĭ �� ���� �� ����
				max_step = step;
			}
		}
		//mid + 1��° ����� ¡�˴ٸ��� �ǳ� �� �ִ°�?
		if (max_step >= k) {
			//�ǳ� �� ���� --> ������ ������ max�� mid��
			right = mid;
		}
		else if (max_step < k) {
			//�ǳ� �� �ִ� --> ������ ������ min�� mid + 1��
			left = mid + 1;
		}
	}
	answer = right;
	return answer;
}