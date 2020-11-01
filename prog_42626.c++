#include<iostream>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;

// prog_42626_더맵게
int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int,vector<int>,greater<int>> pq;

    for(int i=0; i<scoville.size(); i++){
        pq.push(scoville[i]);
    }

    while(pq.top()<K){
        if(pq.size()==1){
            answer=-1; break;
        }
        answer++;
        int n1 = pq.top();
        pq.pop();
        int n2 = pq.top();
        pq.pop();
        pq.push(n1+n2*2);
    }

    return answer;
}