#include <string>
#include <vector>
#include <deque>

using namespace std;

// prog_42586_기능개발
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    deque<int> stack;
    
    int d=0, days=0;
    for(int i=0; i<progresses.size(); i++){
        d = 100-progresses[i];
        days = d/speeds[i];
        if(d%speeds[i]>0) days++;

        stack.push_back(days);
    }
    
    while(!stack.empty()){
        int count=0;
        int fr = stack.front();
        while(fr>=stack.front()&&!stack.empty()){
            stack.pop_front();
            count++;
        }
        answer.push_back(count);
    }
    
    
    return answer;
}