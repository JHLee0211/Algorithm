#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int n = progresses.size();
    vector<int> days(n);
    for(int i = 0; i < n; i++) {
        days[i] = (100 - progresses[i]) / speeds[i];
        if((100 - progresses[i]) % speeds[i] != 0)
            days[i]++;
    }
    
    int cnt = 1, day = days[0];
    for(int i = 1; i < n; i++) {
        if(day < days[i]) {
            answer.push_back(cnt);
            cnt = 1;
            day = days[i];
        }
        else {
            cnt++;
        }
    }
    
    answer.push_back(cnt);
    
    return answer;
}