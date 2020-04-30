/*
날짜: 2020-04-17
분류: 구현
*/

#include <vector>
#include <iostream>

using namespace std;

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	bool answer = true;
	int key_size = key.size();
	int lock_size = lock.size();
	int rotate_key[4][20][20] = { 0 };
	for (int i = 0; i < key_size; i++) {
		for (int j = 0; j < key_size; j++) {
			rotate_key[0][i][j] = key[i][j];
			rotate_key[1][i][j] = key[j][key_size - i - 1];
			rotate_key[2][i][j] = key[key_size - i - 1][key_size - j - 1];
			rotate_key[3][i][j] = key[key_size - j - 1][i];
		}
	}

	int empty_lock = 0;
	for (int i = 0; i < lock_size; i++) {
		for (int j = 0; j < lock_size; j++) {
			if (lock[i][j] == 0)
				empty_lock++;
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int a = -key_size + 1; a < lock_size; a++) {
			for (int b = -key_size + 1; b < lock_size; b++) {
				int temp = 0;
				bool is_open = true;
				for (int j = 0; j < key_size; j++) {
					for (int k = 0; k < key_size; k++) {
						if (a + j >= lock_size || b + k >= lock_size || a + j < 0 || b + k < 0)
							continue;
						if (rotate_key[i][j][k] == 1) {
							if (lock[a + j][b + k] == 0) {
								temp++;
							}
							else {
								temp = -1;
								is_open = false;
								break;
							}
						}
					}
					if (!is_open)
						break;
				}
				if (temp == empty_lock) {
					return true;
				}
			}
		}
		
	}
	return false;
}

int main() {
	vector<vector<int>> key;
	vector<vector<int>> lock;
	vector<int> temp;
	temp.push_back(0);
	temp.push_back(0);
	temp.push_back(0);
	key.push_back(temp);
	temp.clear();
	temp.push_back(1);
	temp.push_back(0);
	temp.push_back(0);
	key.push_back(temp);
	temp.clear();
	temp.push_back(0);
	temp.push_back(1);
	temp.push_back(1);
	key.push_back(temp);
	temp.clear();
	temp.push_back(1);
	temp.push_back(1);
	temp.push_back(1);
	lock.push_back(temp);
	temp.clear();
	temp.push_back(1);
	temp.push_back(1);
	temp.push_back(0);
	lock.push_back(temp);
	temp.clear();
	temp.push_back(1);
	temp.push_back(0);
	temp.push_back(1);
	lock.push_back(temp);
	temp.clear();
	cout << solution(key, lock);
}