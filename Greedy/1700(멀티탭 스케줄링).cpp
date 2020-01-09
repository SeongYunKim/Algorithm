/*
날짜: 2020-01-10
분류: Greedy
*/

#include <iostream>
#include <vector>
#pragma warning (disable: 4996)

using namespace std;

int main() {
	vector<int> q[101];
	int order[101] = { 0 };
	int multitap[101] = { 0 };
	int N, K, change = 0;
	scanf("%d %d", &N, &K);
	for (int i = 0; i < K; i++) {
		scanf(" %d", &order[i]);
		q[order[i]].push_back(i);
	}

	bool out_success = false;
	bool in_multitap = false;
	bool empty_exist = false;
	int max = -1;
	int max_j = -1;

	for (int i = 0; i < K; i++) {
		in_multitap = false;
		out_success = false;
		empty_exist = false;
		max = -1;
		max_j = -1;

		for (int j = 0; j < N; j++) {
			if (multitap[j] == order[i]){
				in_multitap = true;
				break;
			}
		}

		if (!in_multitap) {
			for (int j = 0; j < N; j++) {
				if (multitap[j] == 0) {
					multitap[j] = order[i];
					empty_exist = true;
					break;
				}
			}

			if (!empty_exist) {
				change++;
				for (int j = 0; j < N; j++) {
					if (q[multitap[j]].empty()) {
						multitap[j] = order[i];
						out_success = true;
						break;
					}
				}

				if (!out_success) {
					for (int j = 0; j < N; j++) {
						if (max < q[multitap[j]].front()) {
							max = q[multitap[j]].front();
							max_j = j;
						}
					}
					multitap[max_j] = order[i];
				}
			}
		}

		q[order[i]].erase(q[order[i]].begin());

		/*
		for (int j = 0; j < N; j++) {
			printf("%d ", multitap[j]);
		}
		printf("\n");
		for (int j = 0; j < K; j++) {
			printf("%d: ", j);
			for (int a = 0; a < q[j].size(); a++) {
				printf("%d ", q[j][a]);
			}
			printf("\n");
		}
		*/
	}

	printf("%d", change);
	return 0;
}