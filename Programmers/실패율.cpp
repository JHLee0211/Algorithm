/*
 - https://programmers.co.kr/learn/courses/30/lessons/42889
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct Stage{
    int num;
    int clear;
    int dodal;
    double rate;
    Stage(int idx){num = idx;clear = dodal = rate = 0;}
    bool operator<(const Stage& cmp) const
    {
        if(rate == cmp.rate) return num < cmp.num;
        return rate > cmp.rate;
    }
}Stage;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<Stage> stag;
    for(int i = 0 ; i < N + 1 ; i++) stag.push_back(Stage(i));
    
    
    for(int stage : stages){
        for(int i = 1 ; i < stage ; i++){
            stag[i].clear++;
            stag[i].dodal++;
        }
        if(stage != N + 1)
            stag[stage].dodal++;
    }
    
    
    for(int i = 0 ; i < stag.size() ; i++){
        if(stag[i].dodal == 0) stag[i].rate = 0;
        else{
            stag[i].rate = (double)(stag[i].dodal - stag[i].clear) / (double)(stag[i].dodal);    
        }
    }
    stag[0].rate = -1;
    
    sort(stag.begin(), stag.end());
    for(int i = 0 ; i < stag.size() - 1 ; i++)
        answer.push_back(stag[i].num);
    return answer;
}