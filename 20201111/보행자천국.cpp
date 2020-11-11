#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int MOD = 20170805;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;
    
	vector<vector<int> > H(m + 2, vector<int>(n + 2, 0));
	vector<vector<int> > V(m + 2, vector<int>(n + 2, 0));
	 
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {

			if (i == 1 && j == 1) {
				H[i][j] = 1;
				V[i][j] = 1;
				continue;
			} 

			if (city_map[i-1][j-1] == 0) {
				H[i][j] = (H[i][j - 1] + V[i - 1][j])%MOD;
				V[i][j] = (H[i][j - 1] + V[i - 1][j])%MOD;
			}
			else if (city_map[i-1][j-1] == 1) {
				H[i][j] = 0;
				V[i][j] = 0;
			}
			else {
				H[i][j] = H[i][j - 1];
				V[i][j] = V[i - 1][j];
			}
		}
	}
	
    answer = (H[m][n-1]+V[m-1][n])%MOD;
    return answer;
}