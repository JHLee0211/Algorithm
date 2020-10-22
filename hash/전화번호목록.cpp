#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

bool solution(vector<string> phone_book) {
	bool answer = true;
	sort(phone_book.begin(), phone_book.end());

	set<string> s;
	for (auto x : phone_book) {
		for (int i = 1; i <= x.size(); i++) {
			if (s.find(x.substr(0, i)) != s.end())
				return false;
		}
		s.insert(x);
	}

	return answer;
}