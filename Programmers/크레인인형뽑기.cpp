/*
 - https://programmers.co.kr/learn/courses/30/lessons/64061
*/
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int r_size = board[0].size();
    int c_size = board.size();
    vector<int> q;
    vector<vector<int>> new_board;
    
    for(int i = 0 ; i < r_size ; i++){
        vector<int> col;
        for(int j = c_size - 1 ; j >= 0 ; j--){
            if(board[j][i]){
                   col.push_back(board[j][i]);
            }
        }
        new_board.push_back(col);
    }
    
    for(int i = 0 ; i < moves.size() ; i++){
        int idx = moves[i] - 1;
        if(new_board[idx].size()){
            int item = new_board[idx].back();
            new_board[idx].pop_back();
            q.push_back(item);
            if(q.size() > 1 && q[q.size() - 1] == q[q.size() - 2]){
                answer += 2;
                q.pop_back();
                q.pop_back();
            }
        }
    }
    
    return answer;
}