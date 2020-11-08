#include <iostream>
#include <deque>

using namespace std;

// boj_1158_요세푸스 문제
int main()
{
	deque<int> deq;

	int n,m,popped;
	int count=0;
	cin>>n>>m;

	for(int i=0;i<n;i++){
		deq.push_back(i+1);
	}

	cout<<"<";
	while(!deq.empty()){
		count++;
		popped=deq.front();
		deq.pop_front();
		if(count%m!=0)	deq.push_back(popped);
		else {
			cout<<popped;
			if(!deq.empty()) cout<<", ";
		}
	}
	cout<<">";
	return 0;
}