/*
날짜: 2020-03-31
분류:String
TIP: String Concatenation 시 '+' 연산자 활용
*/

#include <string>
#include <vector>

using namespace std;

string solution(string p) {
	string answer;
	if (p.length() == 0)
		return "";
	int left = 0; int right = 0;
	string u, v;
	bool is_right = true;
	for (int i = 0; i < p.length(); i++) {
		if (p[i] == '(')
			left++;
		else if (p[i] == ')')
			right++;
		if (left < right) {
			is_right = false;
		}
		if (left == right) {
			u = p.substr(0, left + right);
			v = p.substr(left + right);
			if (is_right) {
				answer = u + solution(v);
			}
			else {
				answer = '(' + solution(v) + ')';
				for (int j = 1; j < left + right - 1; j++) {
					if (p[j] == '(')
						answer.push_back(')');
					else if (p[j] == ')')
						answer.push_back('(');
				}
			}
			break;
		}
	}
	return answer;
}