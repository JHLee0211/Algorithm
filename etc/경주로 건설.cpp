#include <string>
#include <vector>
#include <limits.h>
#include <queue>
#include <iostream>
using namespace std;
int n, m;
//int rdir[4] = {0, 0, -1, 1};
//int cdir[4] = {-1, 1, 0, 0};
int rdir[4][3] = 
{
    {0,-1,1},
    {0,-1,1},
    {-1,-1,-1},
    {1,1,1}
};

int cdir[4][3] = 
{
    {-1,-1,-1},
    {1,1,1},
    {0,-1,1},
    {0,-1,1}
};

bool validrange(int r, int c) {
    if(r < 0 || c < 0 || r >= n || c >= m)
        return false;
    return true;
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    n = board.size(), m = board[0].size();
    vector<vector<vector<int>>> cost(n, vector<vector<int>>(m, vector<int>(4, n * m * 600)));
    for(int i = 0; i < 4; i++) {
        cost[0][0][i] = 0;
    }
    queue<pair<int,int>> q;
    q.push(make_pair(0, 0));
    while(!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        if(validrange(r + 1, c) && !board[r + 1][c] && min(cost[r][c][0] + 100, min(cost[r][c][1], cost[r][c][2]) + 600) < cost[r + 1][c][0]) {
            q.push(make_pair(r + 1, c));
            cost[r + 1][c][0] = min(cost[r][c][0] + 100, min(cost[r][c][1], cost[r][c][2]) + 600);
        }
        if(validrange(r - 1, c) && !board[r - 1][c] && min(cost[r][c][3] + 100, min(cost[r][c][1], cost[r][c][2]) + 600) < cost[r - 1][c][3]) {
            q.push(make_pair(r - 1, c));
            cost[r - 1][c][3] = min(cost[r][c][3] + 100, min(cost[r][c][1], cost[r][c][2]) + 600);
        }
        if(validrange(r, c + 1) && !board[r][c + 1] && min(cost[r][c][1] + 100, min(cost[r][c][0], cost[r][c][3]) + 600) < cost[r][c + 1][1]) {
            q.push(make_pair(r, c + 1));
            cost[r][c + 1][1] = min(cost[r][c][1] + 100, min(cost[r][c][0], cost[r][c][3]) + 600);
        }
        if(validrange(r, c - 1) && !board[r][c - 1] && min(cost[r][c][2] + 100, min(cost[r][c][0], cost[r][c][3]) + 600) < cost[r][c - 1][2]) {
            q.push(make_pair(r, c - 1));
            cost[r][c - 1][2] = min(cost[r][c][2] + 100, min(cost[r][c][0], cost[r][c][3]) + 600);
        }
        
    }
    
    answer = cost[n - 1][m - 1][0];
    for(int i = 1; i < 4; i++) {
        answer = min(cost[n - 1][m - 1][i], answer);
    }
    return answer;
}