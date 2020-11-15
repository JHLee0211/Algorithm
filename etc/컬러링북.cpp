#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int h, l;
bool valid(int r, int c) {
    if(r < 0 || c < 0 || r >= h || c >= l)
        return false;
    return true;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    h = m, l = n;

    vector<vector<bool>> visit(m, vector<bool>(n, false));
    int dirr[4] = {0,0,-1,1};
    int dirc[4] = {-1,1,0,0};
    
    for(int i = 0; i < m; i++) {
        for(int j =0; j < n; j++) {
            if(!visit[i][j] && picture[i][j] != 0) {
                number_of_area++;
                int cnt = 0;
                queue<pair<int,int>> q;
                q.push(make_pair(i, j));
                while(!q.empty()) {
                    int r = q.front().first;
                    int c = q.front().second;
                    q.pop();
                    if(visit[r][c])
                        continue;
                    
                    visit[r][c] = true;
                    cnt++;
                    for(int k =0; k < 4;k++) {
                        if(valid(r + dirr[k], c + dirc[k]) && !visit[r + dirr[k]][c + dirc[k]] && picture[r][c] == picture[r + dirr[k]][c + dirc[k]]) {
                            q.push(make_pair(r + dirr[k], c + dirc[k]));
                        }
                    }
                }
                
                max_size_of_one_area = max(max_size_of_one_area, cnt);
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}