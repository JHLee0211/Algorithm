#include <iostream>
#include <vector>
using namespace std;

int main() {

	int N, K;
	cin >> N >> K;

	int maps[201] = { 0, };
	maps[0] = 0;
	for (int i = 1; i <= K; i++)
		maps[i] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			maps[j] = maps[j] + maps[j - 1];
			maps[j] %= 1000000000;
		}
	}
	cout << maps[K] << endl;
	return 0;
}