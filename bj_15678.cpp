//not yet
#include <cstdio>
#include <algorithm>
#include <deque>
using namespace std;

typedef pair<long long, int> pli;

int n, d;
long long a, now, ans = -1e9;
deque<pli> deq;

int main() {
	scanf("%d %d", &n, &d);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a);
		while (!deq.empty() && deq.front().second + d < i) deq.pop_front();
		now = max(a, a + deq.front().first);
		ans = max(ans, now);
		while (!deq.empty() && deq.back().first <= now) deq.pop_back();
		deq.push_back(pli(now, i));
	}

	printf("%lld", ans);

	return 0;
}