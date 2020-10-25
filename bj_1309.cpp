#include <iostream>
#include <vector>
using namespace std;
int N;
int maps[100001][100001];
int main() {
	cin >> N;
	int answer = 0;
	
	maps[1][0] = 1;
	maps[1][1] = 2;

	maps[2][0] = 1;
	maps[2][1] = 4;
	maps[2][2] = 2;
	for (int i = 3; i <= N; i++) {
		maps[i][1] = maps[i - 1][1] + 2;
		maps[i][i] = 2;
		maps[i][0] = 1;
	}

	for (int i = 3; i <= N; i++) {
		maps[i][2] = maps[i - 1][1] + 2 * (i - 2) + maps[i - 1][2];
	}

	for (int i = 4; i <= N; i++) {
		for (int j = 3; j < N; j++) {
			maps[i][j] = maps[i - 1][j - 1]+ maps[i - 2][j - 1]+maps[i - 1][j];
		}
	}
	
	
	for (int i = 0; i <= N; i++) {
		//cout << maps[N][i] << endl;
		answer += maps[N][i];
	}
	cout << answer << endl;
	return 0;
}