#include <iostream>
#include <math.h>
#define Max 100000000000
using namespace std;
int dp[46][5][5] = { 0, };

int main() {

	
	//짝수: 2로 나누기
	
	
	int N; long long  B;
	cin >> N >> B;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> dp[0][i][j];
		}
	}
	for (int i = 1; i <= 45; i++) {
		int x[5][5] = { 0, };
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				for (int m = 0; m < N; m++) {
					x[j][k] += dp[i - 1][j][m] * dp[i - 1][m][k];
					x[j][k] %= 1000;
				}
				
			}
			
		}
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				dp[i][j][k]= x[j][k];
			}
		}
		
	}
	int answer[5][5] = {
		{1,0,0,0,0},
		{0,1,0,0,0},
		{0,0,1,0,0},
		{0,0,0,1,0},
		{0,0,0,0,1}
	};
	for (int i = 45; i >= 0;i--) {
		if (B == 0) break;
		if (B >= pow(2, i)) {
			int x[5][5] = { 0, };
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < N; k++) {
					
					for (int m = 0; m < N; m++) {
						x[j][k] += answer[j][m] * dp[i][m][k];
						x[j][k] %= 1000;
					}
					
				}

			}
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < N; k++) {
					answer[j][k] = x[j][k];
					
				}
			}
			

			B -= pow(2, i);
		}

	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << answer[i][j] << " ";
		}cout << endl;
	}
	return 0;
}