#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> triangle) {
	int answer = 0;
	int dp[500][500];
	dp[0][0] = triangle[0][0];
	for (int i = 1; i < triangle.size(); i++) {
		dp[i][0] = dp[i - 1][0] + triangle[i][0];
		for (int j = 1; j < triangle[i].size(); j++) {
			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j];
		}
	}

	for (int j = 0; j < triangle.size(); j++) {
		answer = max(answer, dp[triangle.size() - 1][j]);
	}

	return answer;
}