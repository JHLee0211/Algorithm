#include <iostream>
#include <cstring>

using namespace std;

// boj_1463_1로만들기
int d[1000001];

int recur(int i){
	if(i==1) return  0;
	if(d[i]>0) return d[i];
	d[i]=recur(i-1)+1;
	if(i%2==0) d[i]=min(d[i],recur(i/2)+1);
	if(i%3==0) d[i]=min(d[i],recur(i/3)+1);
	return d[i];
}

int main()
{
	int num;

	cin>>num;
	memset(d,0,sizeof(int)*(num+1));

	cout<<recur(num);
	return 0;
}