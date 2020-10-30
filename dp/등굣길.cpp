#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    vector<vector<int>> dp(m, vector<int>(n, 0));
    vector<vector<bool>> p(m, vector<bool>(n, false));
    dp[0][0] = 1;
    for(auto puddle : puddles) {
        p[puddle[0] - 1][puddle[1] - 1] = true;
    }
    
    for(int i = 1; i < m; i++) {
        if(p[i][0]) {
            break;
        }
        
        dp[i][0] = dp[i - 1][0];
    }
    
    for(int j = 1; j < n; j++) {
        if(p[0][j]) {
            break;
        }
        
        dp[0][j] = dp[0][j - 1];
    }
        
    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
            if(p[i][j]) {
                continue;
            }
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            dp[i][j] %= 1000000007;
        }
    }
    return dp[m - 1][n - 1];
}