#include<iostream>
#include<algorithm>
//incomplete
using namespace std;

int main() {
	int a, b, v;
	cin >> a >> b >> v;
	long long last = v;
	long long first = 0;
	long long mid;
	long long ans;
	while (first <= last) {
		mid = (first + last) / 2;
		if (v <= (mid - 1)*(a - b) + a)
		{
			last = mid - 1;
			ans = mid;
		}
		else {
			first = mid + 1;
		}
	}
	cout << ans;
}