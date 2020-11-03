/*
 - https://programmers.co.kr/learn/courses/30/lessons/17681
*/
#include <string>
#include <vector>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for(int i = 0 ; i < arr1.size() ; i++){
        arr1[i] |= arr2[i];
    }
    int w = 0;
    for(int i : arr1){
        string s;
        for(int j = 0 ; j < n ; j++){
            s = i % 2 == 0 ? " " + s : "#" + s;
            i = i >> 1;
        }
        answer.push_back(s);
    }
    
    return answer;
}