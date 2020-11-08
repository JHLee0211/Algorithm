#include <iostream>
#include <vector>
#include <stack>
#define P pair<int,int>
using namespace std;
vector<int> v(100000);
bool isExist(stack<int> st, int idx) {
	while (!st.empty()) {
		if (v[st.top()] == v[idx]) {
			return true;
		}
		else {
			st.pop();
		}
	
	}
	return false;
}
int main() {


	
	int N;
	cin >> N;
	
	for (int i = 0; i < N; i++)
		cin >> v[i];

	
	stack<int> st;
	st.push(0);
	int answer = 0;
	for (int i = 1; i < N; i++) {
		if (v[st.top()] < v[i]) {
			st.push(i);
		}
		else if (v[st.top()] == v[i]) {
			continue;
		}
		else {
			stack<int> tmp_st;
			
			cout << "idx: " << i << endl;
			while (!st.empty()) {
				int x = st.top();
				

				int newans = (i - x) * v[x];
				cout << newans << endl;
				answer = answer < newans ? newans : answer;
				
				if (v[x]> v[i]) {
					v[x] = v[i];
				}
				tmp_st.push(x);
				st.pop();
			}

			while (!tmp_st.empty()) {
				if(!isExist(st, tmp_st.top()))
					st.push(tmp_st.top());
				tmp_st.pop();
			}
			st.push(i);
		}
	}

	int lastx = st.top();
	cout << "last " << endl;
	while (!st.empty()) {
		int x = st.top();
		if (x > lastx) {
			x = lastx;
		}
		int newans = (N - x) *v[x];
		cout << newans<< endl;
		answer = answer < newans ? newans : answer;
		st.pop();
	}
	cout << answer << endl;
	return 0;
}