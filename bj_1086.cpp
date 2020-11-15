#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <string>
#include <stack>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int INF = 987654321;
const int mod = 1e9 + 7;

int n, k;
vector<string> vec;
vector<int> modk;
vector<vector<ll>> dp;
vector<int> digitnum;

ll gcd(ll a, ll b)
{
	if (b > a) return gcd(b, a);

	if (b == 0) return a;

	return gcd(b, a%b);
}

int getmod(const string& str)
{
	int pow = 1;
	int ret = 0;
	int strsize = str.size();
	for (int i = strsize - 1; i >= 0; i--)
	{
		ret += (str[i] - '0') * pow;
		ret %= k;

		pow *= 10;
		pow %= k;
	}

	return ret;
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	vec = vector<string>(n);
	modk = vector<int>(n);
	digitnum = vector<int>(1 << n, 0);

	vector<int> sz(n, 0);
	vector<int> powk(1000, 1);
	vector<ll> factorial(16, 1);

	for (int i = 1; i < 16; i++)
	{
		factorial[i] = factorial[i - 1] * i;
	}

	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
		sz[i] = vec[i].size();
	}

	for (int i = 0; i < (1 << n); i++)
	{
		for (int x = 0; x < n; x++)
		{
			if ((i & (1 << x)) != 0)
			{
				digitnum[i] += sz[x];
			}
		}
	}

	cin >> k;
	dp = vector<vector<ll>>(1 << n, vector<ll>(k, 0));

	powk[0] = 1 % k;
	for (int i = 1; i < 1000; i++)
	{
		powk[i] = (powk[i - 1] * 10) % k;
	}

	for (int i = 0; i < n; i++)
	{
		modk[i] = getmod(vec[i]);
	}


	dp[0][0] = 1;
	for (int i = 0; i < (1 << n); i++)
	{
		for (int j = 0; j < k; j++)
		{
			if (dp[i][j])
			{
				for (int x = 0; x < n; x++)
				{
					if ((i & (1 << x)) == 0)
					{
						int newmod = (j + powk[digitnum[i]] * modk[x]) % k;

						dp[i | (1 << x)][newmod] += dp[i][j];
					}
				}
			}
		}
	}

	if (!dp[(1 << n) - 1][0]) cout << "0/1";
	else
	{
		ll g = gcd(factorial[n], dp[(1 << n) - 1][0]);

		cout << dp[(1 << n) - 1][0] / g << "/" << factorial[n] / g;
	}


	return 0;
}