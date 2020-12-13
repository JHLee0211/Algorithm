#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer(2, 1);
    map<string, int> m;
    int minlen = gems.size();
    int start = 1, end = 1;
    for(int i = 0; i < gems.size(); i++) {
        if(m[gems[i]] == 0) {
            end = i + 1;
            answer[0] = start;
            answer[1] = end;
        }
        else if(gems[start - 1] == gems[i]) {
            int minstart = i + 1;
            for(auto mgem : m) {
                if(gems[i] != mgem.first)
                    minstart = min(minstart, mgem.second);
            }
            start = minstart;
            end = i + 1;
            
            if(answer[1] - answer[0] > end - start) {
                answer[0] = start;
                answer[1] = end;
            }
        }
        m[gems[i]] = i + 1;
    }
    
    if(answer[1] - answer[0] > end - start) {
        answer[0] = start;
        answer[1] = end;
    }
    
    return answer;
}