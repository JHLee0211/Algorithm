#include <bits/stdc++.h>
using namespace std;
map<pair<int, int>, int> pig;
int solve(int i, int j){
	if(i>=40)
		return 0;
	if(j==1)
		return i==0;
	if(j<=1)
		return 0;
	if(pig.count({i, j})!=0)
		return pig[{i, j}];
	pig[{i, j}]=solve(i+1, j-1);
	if(i>1&&j%3==0)
		pig[{i, j}]+=solve(i-2, j/3);
	return pig[{i, j}];
}
int solution(int n) {
	return solve(0,n);
}