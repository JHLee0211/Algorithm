#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> m;
    for(auto x : clothes) {
        m[x[1]]++;
    }
    
    for(auto x : m) {
        answer *= x.second + 1;
    }
    
    answer--;
    
    return answer;
}