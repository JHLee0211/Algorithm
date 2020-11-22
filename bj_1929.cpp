#include <iostream>
using namespace std;
int maps[1000001] = { 0, };
int main() {
	//incomplete
	int M, N;
	cin >> M >> N;
	maps[1] = 1;
	for (int i = 2; i <= N; i++) {
		if (maps[i] == 0) {

			for (int j = i;; j++) {
				unsigned int cur = i * j;
				if (cur > N) {
					
					break;
				}
				
				maps[cur] = 1;
			}
		}
	}
	for (int i = M; i <= N; i++) {
		if (maps[i] == 0) {
			cout << i << endl;
		}
	}
	return 0;
}