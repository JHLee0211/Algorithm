/*
 - https://programmers.co.kr/learn/courses/30/lessons/64065
 - 숫자의 빈도수가 큰 숫자부터 튜플의 앞쪽에 나오는 원소인 점을 이용
 - map으로 숫자 빈도수 counting
 - map의 value(빈도수)가 큰 순으로 정렬한 다음에 answer 벡터 채움
*/
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int>& a, pair<int, int>& b)
{
    return a.second > b.second;
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<pair<int, int> > ans;
    map<int, int> maps;
    s = s.substr(1, s.length() - 2); // 입력의 처음과 마지막 괄호 없앰
    
    istringstream iss(s);
    string token;
    while(getline(iss, token, ',')){ // 쉼표를 기준으로 토큰화
        if(token[0] == '{') token = token.substr(1);
        if(token[token.length() - 1] == '}') token = token.substr(0, token.length() - 1);
        int ntoken = stoi(token);
        maps[ntoken] = maps[ntoken] + 1;       
    }

    for(auto it = maps.begin() ; it != maps.end() ; it++){
        ans.push_back(*it);
    }
    sort(ans.begin(), ans.end(), cmp);
    for(int i = 0 ; i < ans.size() ; i++){
        answer.push_back(ans[i].first);
    }
    return answer;
}