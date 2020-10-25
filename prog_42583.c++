#include<iostream>
#include<vector>
#include<deque>

using namespace std;

// programmers_42583_다리를 지나는 트럭
int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    deque<int> wait(0);
    vector<pair<int,int>> working(0);

    for(int x:truck_weights){
        wait.push_back(x);
    }
    
    int wei = wait.front();
    working.push_back(make_pair(wei, 0));
    wait.pop_front();

    while(!working.empty()){
        answer++;
        for(int i=0; i<working.size(); i++){
            working[i].second++;
        }
        if(working[0].second > bridge_length){
            wei -= working[0].first;
            working.erase(working.begin());
        }
        if(!wait.empty() && wei + wait.front() <= weight){
            int nextTruck = wait.front();
            wait.pop_front();
            wei += nextTruck;
            working.push_back(make_pair(nextTruck,1));
        }
    }    
    return answer;
}