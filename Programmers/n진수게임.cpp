/*
 - https://programmers.co.kr/learn/courses/30/lessons/17687
*/
#include <string>
#include <vector>

using namespace std;
string Hexa[16] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F"};
string solution(int n, int t, int m, int p) {
    string answer = "", fullstr = "0";
    int total_len = (m + 1) * t, cur_len = 1, num = 1;
    while(cur_len < total_len){
        string conv;
        int convn = num;
        while(convn){
            conv = Hexa[convn % n] + conv;
            convn /= n;
        }
        fullstr += conv;
        cur_len += conv.size();
        num++;
    }
    
    for(int i = 0 ; i < t ; i++){
        answer += fullstr[p - 1 + i * m];
    }
    
    return answer;
}