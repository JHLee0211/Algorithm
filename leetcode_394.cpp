#include <stack>
#include <string>
using namespace std;
class Solution {
public:
	bool allNums(string s) {
		for (auto c : s) {
			if (c >= '0'&&c <= '9') {

			}
			else
				return false;
		}
		return true;
	}
	string decodeString(string s) {
		
		stack<string> st;

		for (auto c : s) {
			if (c >= '0'&&c <= '9') {
				if (st.empty())
					st.push(string(1, c));
				else if (allNums(st.top())) 
					st.top() += c;
				else 
					st.push(string(1, c));
			}
			else if (c != ']') {
				if (st.empty())
					st.push(string(1, c));
				else
					st.top() += c;
			}
			else {
				
				string cur = st.top();
				st.pop();
				int idx = 1;
				int num = 0;
				string loop;
				string tmp_num;
				for (auto cur_c : cur) {
					if (cur_c >= '0'&&cur_c <= '9') {
						tmp_num += cur_c;
					}
					else if (cur_c != '[') {
						loop += cur_c;
					}

				}
				idx = tmp_num.size() - 1;
				for (auto cur_c : tmp_num) {
					num += (cur_c - '0')*(pow(10, idx));
					idx--;
				}
				string cur_ans;
				while (num--) {
					cur_ans += loop;
				}

				if (st.empty()) {
					st.push(cur_ans);
				}
				else {
					st.top().append(cur_ans);
				}
			}
		}
		if (st.empty())
			st.push("");
		return st.top();
	}
};