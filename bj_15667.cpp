#include <iostream>
#include <string>
#include <stack>

using namespace std;
int main() {


	
	int N;
	cin >> N;
	string str;
	cin >> str;
	int pan=0;
	for (int i = 0; i < N; i++) {
		if (str[i] == '(') {
			pan = pan | (1 << i);
		}
		
	}
	cout << pan << endl;
	int Q;
	cin >> Q;
	while (Q--) {
		int t, a, b;
		cin >> t >> a >> b;
		a--, b--;
		if (t == 1) {
			int x = 0;
			int tmp_pan = pan;
			int tmp_first = tmp_pan >> (b+1);
			tmp_first = tmp_first << (b+1);
			int tmp_mid = tmp_pan << (32 - b+1);
			tmp_mid = tmp_mid >> (32 - b +1);
			tmp_mid = tmp_mid >> (a+1);
			tmp_mid = tmp_mid << (a+1);
			int tmp_last = tmp_pan << (32-a+1);
			tmp_last = tmp_last >> (32 -a+1);
			x = tmp_first | x;
			x = tmp_mid | x;
			x = tmp_last | x;
			pan = x;
			cout << tmp_first << " " << tmp_mid<< " "<<tmp_last<< endl;
		}
		else {
			stack<int> st;
			int tmp_pan = pan;
			for (int i = a; i <= b; i++) {
				int x = pan & (1 << i);
				x = x >> i;
				if (st.empty()) {
					st.push(x);

				}
				else {
					if (x != st.top()&&st.top()==1) {
						//¦
						st.pop();
					}
					else {
						st.push(x);
					}
				}
			}
			//
			cout << b - a + 1 + st.size() << endl;
			pan = tmp_pan;
		}
	}

	return 0;
}