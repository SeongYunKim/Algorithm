/*
날짜: 2020-04-07
분류: LIS(Longest Increasing Subsequence), lower bound
TIP: lower bound를 이용한 LIS 시간복잡도 = O(NlogN)
배열을 순회하며
case1) LIS 벡터의 마지막 요소보다 배열값이 크면 LIS 벡터에 추가
case2) 작으면 lower bound 위치의 LIS 벡터값을 변경

LIS의 길이 뿐만 아니라 각 요소를 알고싶다면
https://yhwan.tistory.com/21
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#pragma warning (disable: 4996)

using namespace std;

int n;
vector<pair<int, int>> v1, record;
vector<int> lis;
int visited[500001] = { 0 };

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}

int main() {
	int start, end;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &start, &end);
		v1.push_back({ start, end });
		visited[start] = 1;
	}
	
	sort(v1.begin(), v1.end(), cmp);

	lis.push_back(v1[0].second);
	record.push_back({ 0, v1[0].first });
	for (int i = 1; i < n; i++) {
		if (v1[i].second > lis[lis.size() - 1]) {
			lis.push_back(v1[i].second);
			record.push_back({ lis.size() - 1, v1[i].first });
		}
		else {
			auto it = lower_bound(lis.begin(), lis.end(), v1[i].second);
			*it = v1[i].second;
			record.push_back({ lower_bound(lis.begin(), lis.end(), v1[i].second) - lis.begin(), v1[i].first });
		}
	}

	int temp_n = lis.size() - 1;
	printf("%d\n", n - lis.size());
	for (int i = record.size() - 1; i >= 0; i--) {
		if (record[i].first == temp_n) {
			visited[record[i].second] = 0;
			temp_n--;
		}
		if (temp_n == -1)
			break;
	}
	
	
	for (int i = 0; i < 500001; i++) {
		if (visited[i])
			printf("%d\n", i);
	}
	
	return 0;
}