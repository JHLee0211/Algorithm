/*
 - https://programmers.co.kr/learn/courses/30/lessons/17682
*/
#include <string>
#include <vector>

#define ISNUM(n) (n <= '9' && n >= '0')

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    vector<int> stack;
    for(int i = 0 ; i < dartResult.size() ; i++){
        if(ISNUM(dartResult[i])){
            int size = 1;
            if(ISNUM(dartResult[i + 1])){
                size += 1;
            }
            string num = dartResult.substr(i, size);
            char c = dartResult[i + size];
            int square =  (c == 'S' ? 1 : (c == 'D' ? 2 : 3));
            int score = 1;
            for(int i = 0 ; i < square ; i++) {
                score *= stoi(num);
            }
            stack.push_back(score);
            i += size;
        }else if(dartResult[i] == '*'){
            stack[stack.size() - 1] *= 2;
            if(stack.size() > 1)
                stack[stack.size() - 2] *= 2;
        }
        else if(dartResult[i] == '#'){
            stack[stack.size() - 1] *= -1;
        }
    }
    for(int i : stack)
        answer += i;
    
    
    return answer;
}