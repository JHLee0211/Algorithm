#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<int> bask;
    vector<vector<int>> con(board[0].size());
    for(int i = board.size() - 1; i >= 0; i--) {
        for(int j = 0; j < board[i].size(); j++) {
            if(board[i][j] != 0) {
                con[j].push_back(board[i][j]);
            }
        }
    }
    
    for(auto move : moves) {
        move--;
        if(con[move].empty())
            continue;
        
        if(!bask.empty() && bask.back() == con[move].back()) {
            bask.pop_back();
            answer += 2;
        }
        else {
            bask.push_back(con[move].back());
        }
        
        con[move].pop_back();
    }
    
    return answer;
}