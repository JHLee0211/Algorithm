#include <iostream>
#include <vector>
#include <queue>
#define P pair<int,int>
using namespace std;
int v[101][101];
long long maps[101][101] = { 0, };

int main() {

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> v[i][j];
		}
	}
	int answer = 0;
	
	maps[0][0] = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (maps[i][j] == 0) continue;
			if (i == N - 1 && j == N - 1) continue;
			//cout << endl;
			maps[i + v[i][j]][j] += maps[i][j];
			maps[i][j+v[i][j]]+= maps[i][j];
			//cout << i + v[i][j] << endl;
			
		}
	}

	cout << maps[N-1][N-1] << endl;
	return 0;
}