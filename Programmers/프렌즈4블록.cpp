/*
 - https://programmers.co.kr/learn/courses/30/lessons/17679
*/
#include <string>
#include <vector>
#include <cstring>
using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0, cnt = 0;
    int chk[m][n];

    do{
        cnt = 0;
        memset(chk, 0, sizeof(chk));
        for(int i = 0 ; i < m - 1 ; i++){
            for(int j = 0 ; j < n - 1 ; j++){
                if(board[i][j] == 0) continue;
                // 4각형 모양으로 블록이 동일할 경우 모두 마킹
                if(board[i][j] == board[i][j + 1] && board[i][j] == board[i+1][j] &&
                  board[i][j] == board[i+1][j+1]){
                    chk[i][j] = chk[i][j+1] = chk[i+1][j] = chk[i+1][j+1] = 1;
                }
            }
        }

        for(int i = 0 ; i < m; i++){
            for(int j = 0 ; j < n ; j++){
                if(chk[i][j]){ //마킹된거 없애기
                    board[i][j] = 0;
                    cnt++;
                }
            }
        }

        // 빈공간 채우기
        for(int j = 0 ; j < n ; j++){
            int idx = -1;
            for(int i = m - 1; i >= 0 ; i--){
                if(idx == -1 && board[i][j] == 0){
                    idx = i; // 첫 번째 빈 공간의 위치
                }
                else if(idx != -1 && board[i][j] != 0){ // 블록이 존재하고, 아래에 빈 공간이 존재할 때
                    board[idx][j] = board[i][j];
                    board[i][j] = 0; // 블록을 빈 공간으로 밑까지 땡기고, 원래 있던 위치를 빈 공간으로 만들어줌
                    i = idx;
                    idx = -1;
                }
            }
        }
        
        answer += cnt;
    }while(cnt);
    
    return answer;
}