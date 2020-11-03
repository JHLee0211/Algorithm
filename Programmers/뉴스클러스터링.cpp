/*
 - https://programmers.co.kr/learn/courses/30/lessons/17677
 - set_union & set_intersection 이거 참 괜찮네...
*/
#include <string>
#include <algorithm>
#include <vector>
#define ISALPHA(c) ((c <= 'Z' && c >= 'A') || (c <= 'z' && c >= 'a'))

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    vector<string> substr1, substr2;
    
    for(int i = 0 ; i < str1.size() - 1 ; i++){
        if(ISALPHA(str1[i]) && ISALPHA(str1[i + 1])) {
            string push = str1.substr(i, 2);
            if(push[0] >= 'a' && push[0] <= 'z') push[0] = push[0] - ('z' - 'Z');
            if(push[1] >= 'a' && push[1] <= 'z') push[1] = push[1] - ('z' - 'Z');
            
            substr1.push_back(push);
        }
    }    
    for(int i = 0 ; i < str2.size() - 1 ; i++){
        if(ISALPHA(str2[i]) && ISALPHA(str2[i + 1])) {
            string push = str2.substr(i, 2);
            if(push[0] >= 'a' && push[0] <= 'z') push[0] = push[0] - ('z' - 'Z');
            if(push[1] >= 'a' && push[1] <= 'z') push[1] = push[1] - ('z' - 'Z');
            substr2.push_back(push);
        }
    }
    // 교집합 (set_intersection) 구하기 위해 두 벡터 정렬
    sort(substr1.begin(), substr1.end());
    sort(substr2.begin(), substr2.end());
    
    //합집합
    vector<string> uni(substr1.size() + substr2.size()), its(substr1.size() + substr2.size());
    auto iter = set_union(substr1.begin(), substr1.end(), substr2.begin(), substr2.end(), uni.begin());
    uni.erase(iter, uni.end());
    //교집합
    iter = set_intersection(substr1.begin(), substr1.end(), substr2.begin(), substr2.end(), its.begin());
    its.erase(iter, its.end());
    
    if(its.size() == 0 && uni.size() == 0) answer = 65536;
    else{
        double val = (double)its.size() / (double)uni.size();
        answer = (int)(val*65536);
    }
    
    
    return answer;
}
