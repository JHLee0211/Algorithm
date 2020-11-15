#include <vector>

using namespace std;

int MOD = 20170805;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;
    
    vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(2, 0)));
    dp[0][0][0] = 1; // row
    dp[0][0][1] = 1; // col
    for(int i = 1; i < n; i++) { 
        if(city_map[0][i] == 1)
            break;
        dp[0][i][0] = dp[0][i - 1][0];
    } 
    for(int i = 1; i < m; i++) {
        if(city_map[i][0] == 1)
            break;
        dp[i][0][1] = dp[i - 1][0][1];
    }
    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++) {
            if(city_map[i][j] == 1)
                continue;
            if(city_map[i - 1][j] == 2) {
                dp[i][j][1] = dp[i - 1][j][1];
            }
            else {
                dp[i][j][1] = dp[i - 1][j][0] + dp[i - 1][j][1];
            }
            if(city_map[i][j - 1] == 2) {
                dp[i][j][0] += dp[i][j - 1][0];
            }
            else {
                dp[i][j][0] = dp[i][j - 1][0] + dp[i][j - 1][1];
            }
            
            dp[i][j][0] %= MOD;
            dp[i][j][1] %= MOD;
        }
    }
    
    answer = (dp[m - 1][n - 1][1] + dp[m - 1][n - 1][0]) % MOD;
    return answer;
}