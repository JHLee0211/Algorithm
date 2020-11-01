#include<iostream>
#include<vector>
#include<bitset>
#include<algorithm>
#define INF 10000000
using namespace std;
int dist[16][16];
int dp[70000][16];
int main() {
	
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> dist[i][j];
			if (dist[i][j] == 0)
				dist[i][j] = INF;
		}
	}
	
	for (int i = 1; i < N; i++) {
		dp[1 << i][i] = INF;
	}
	for (int i = 2; i <= N;i++) {
		vector<int> v;
		for (int j = 0; j < i; j++) {
			v.push_back(1);
		}
		for (int j = 0; j < N - i; j++) {
			v.push_back(0);
		}
		sort(v.begin(), v.end());
		do {
			int cur = 0;
			for (int j = 0; j < N; j++) {
				cur = cur | (v[j] << j);
			}
			for (int j = 0; j < N; j++) {
				if (v[j] == 1) {
					int not_j = cur & ~(1 << j);
					dp[cur][j] = INF;
					for (int k = 0; k < N; k++) {
						if (k == j) continue;
						if (v[k] == 1) {
							int newdist= dp[not_j][k] + dist[k][j];
							dp[cur][j] = dp[cur][j] < newdist ? dp[cur][j] : newdist;
						}
						
					}
				}
			}
		} while (next_permutation(v.begin(), v.end()));
	}
	int full = (1 << N) - 1;
	int ans = INF;
	for (int i = 1; i < N; i++) {
		ans = ans < dp[full][i] + dist[i][0] ? ans : dp[full][i] + dist[i][0];
	}
	cout << ans << endl;
	return 0;
}