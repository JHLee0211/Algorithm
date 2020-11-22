#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

vector<string> solution(vector<string> record) {
	vector<string> answer;
	//vector<int> list;
	map<string, string> user;
	map<string, vector<int>> list;
	vector<pair<string, bool>> change;
	int i = 0;
	for (auto x : record) {
		if (x.substr(0, 5) == "Enter") {
			int idx1 = x.find(' ', 6);
			user[x.substr(6, idx1 - 6)] = x.substr(idx1 + 1, x.size() - idx1);
		}
		else if (x.substr(0, 5) == "Leave") {
		}
		else {
			int idx1 = x.find(' ', 7);
			user[x.substr(7, idx1 - 7)] = x.substr(idx1 + 1, x.size() - idx1);
		}
	}

	for (auto x : record) {
		if (x.substr(0, 5) == "Enter") {
			int idx1 = x.find(' ', 6);
			answer.push_back(user[x.substr(6, idx1 - 6)] + "님이 들어왔습니다.");
		}
		else if (x.substr(0, 5) == "Leave") {
			int idx1 = x.find(' ', 6);
			answer.push_back(user[x.substr(6, idx1 - 6)] + "님이 나갔습니다.");
		}
	}

return answer;
}