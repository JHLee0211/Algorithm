#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> money) {
    int answer = 0;
    int n = money.size();
    vector<vector<int>> dp(n, vector<int>(2, 0)); // 0부터 시작, 1부터 시작
    
    if(n == 3) {
        return max(money[0], max(money[1], money[2]));
    }
    
    dp[0][0] = money[0];
    dp[0][1] = 0;
    dp[1][0] = money[1];
    dp[1][1] = money[1];
    dp[2][0] = dp[0][0] + money[2];
    dp[2][1] = money[2];

    
    for(int i = 3; i < n; i++) {
        dp[i][0] = max(dp[i - 2][0], dp[i - 3][0]) + money[i];
        dp[i][1] = max(dp[i - 2][1], dp[i - 3][1]) + money[i];
    }
    
    answer = max(dp[n - 1][1], max(dp[n - 2][0], dp[n - 3][0]));
    
    return answer;
}