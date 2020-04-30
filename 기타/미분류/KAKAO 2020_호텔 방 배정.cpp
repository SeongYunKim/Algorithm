/*
��¥: 2020-04-02
�з�: ����(Map), ȿ����
TIP: key: ó�� ���ϴ� ���ȣ value: ����ִ� ���� ���� �� ��ȣ
*/


#include <iostream>
#include <vector>
#include <map>
#pragma warning (disable: 4996)

using namespace std;

vector<long long> solution(long long k, vector<long long> room_number);

int main() {
	vector<long long> llv;
	vector<long long> room_v;
	room_v.push_back(1);
	room_v.push_back(3);
	room_v.push_back(4);
	room_v.push_back(1);
	room_v.push_back(3);
	room_v.push_back(1);
	llv = solution(10, room_v);
	for (int i = 0; i < llv.size(); i++) {
		printf("%lld ", llv[i]);
	}
	return 0;
}

vector<long long> solution(long long k, vector<long long> room_number) {
	vector<long long> answer;
	map<long long, long long> m;
	for (int i = 0; i < room_number.size(); i++) {
		//map�� value���� ������Ʈ �� ��带 ��� ����
		vector<long long> v;
		long long next = room_number[i];
		v.push_back(next);
		auto it = m.find(next);
		while (it != m.end()) {
			it = m.find(m[next]);
			v.push_back(m[next]);
			next = m[next];
		}
		v.push_back(next);
		it = m.find(next + 1);
		if (it == m.end()) {
			m[next] = next + 1;
		}
		else {
			m[next] = m[next + 1];
		}
		answer.push_back(next);
		for (int i = 0; i < v.size(); i++) {
			m[v[i]] = m[next];
		}
	}
	return answer;
}

/*
ó�� �����ߴ� ���
vector<long long> solution(long long k, vector<long long> room_number) {
	vector<long long> answer;
	map<long long, long long> m;
	for (int i = 0; i < room_number.size(); i++) {
		auto it = m.find(room_number[i]);
		if (it == m.end()) {
			//�� ��
			auto it2 = m.find(room_number[i] + 1);
			if (it2 == m.end()) {
				m[room_number[i]] = room_number[i] + 1;
			}
			else {
				m[room_number[i]] = m[room_number[i] + 1];
			}
			answer.push_back(room_number[i]);
		}
		else {
			//�� �� X
			vector<long long> v;
			v.push_back(room_number[i]);
			long long next = m[room_number[i]];
			while (true) {
				auto it2 = m.find(next);
				if (it2 == m.end()) {
					auto it3 = m.find(next + 1);
					if (it3 == m.end()) {
						m[next] = next + 1;
					}
					else {
						m[next] = m[next + 1];
					}
					answer.push_back(next);

					for (int i = 0; i < v.size(); i++) {
						m[v[i]] = m[next];
					}
					break;
				}
				else {
					v.push_back(next);
					next = m[next];
				}
			}
		}
	}
	return answer;
}
*/