#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> cm, pm;
    for(auto c : completion) {
        cm[c]++;
    }
    
    for(auto p : participant) {
        pm[p]++;
    }
    
    for(auto p : pm) {
        if(cm.find(p.first) == cm.end() || cm[p.first] < p.second)
            return p.first;
    }
    
    return answer;
}