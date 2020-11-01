#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>

using namespace std;

// programmers_42587_프린터
int solution(vector<int> priorities, int location) {
    queue<int> prior;
    vector<int> sort;
    for(int i=0; i<priorities.size(); i++) {
        prior.push(i);
    }
    while(!prior.empty()) {
        int now_index = prior.front();
        prior.pop();
        if(priorities[now_index] != *max_element(priorities.begin(),priorities.end())) {
            prior.push(now_index);
        } else {
            sort.push_back(now_index);
            priorities[now_index] = 0;
        }
    }
    for(int i=0; i<sort.size(); i++) {
        if(sort[i] == location) return i+1;
    }
}