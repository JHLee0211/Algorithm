#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    map<int, int> m;
    int num = 0;
    for(int i = 2; i < s.size() - 2; ) {
        int idx = s.find("}", i);
        int cnt = 0;
        for(int nowidx = i; nowidx < idx; ) {
            cnt++;
            if(s.find(",", nowidx + 1) == string::npos) {
                m[stoi(s.substr(nowidx, idx - nowidx))]++;
                break;
            }
            
            int nextidx = s.find(",", nowidx + 1);
            if(nextidx > idx) {
                m[stoi(s.substr(nowidx, idx - nowidx))]++;
                break;
            }
            
            m[stoi(s.substr(nowidx, nextidx - nowidx))]++;
            nowidx = nextidx + 1;
        }
        num = max(cnt, num);
        i = idx + 3;
    }
    answer.assign(num, 0);
    for(auto x: m) {
        answer[num - x.second] = x.first;
    }
    
    return answer;
}