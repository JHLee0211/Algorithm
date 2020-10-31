/*
 - https://programmers.co.kr/learn/courses/30/lessons/64064
 - 다시풀어보자.. 너무 이상하게 풀었다
*/

#include <string>
#include <vector>
#include <set>
using namespace std;

vector<string> guser_id, gbanned_id;
vector<vector<int> > stars;
set<vector<int> > answer;

bool visit[9];

void dfs(int depth){ // banned_id를 하나씩 user_id에 대응되게 조합해봄
    if(depth >= gbanned_id.size()){ // 모든 banned_id를 조합한 경우
        vector<int> tmp;
        for(int i = 0 ; i < guser_id.size() ; i++){ // 해당 조합이 이미 만들어진 배열 만들어서
            if(visit[i]){
                tmp.push_back(i);
            }
        }
        answer.insert(tmp); // set에 넣어보기, 이미 조합이 된 경우엔 insert 안될 거임
    }else{
        string cur = gbanned_id[depth];

        for(int i = 0 ; i < guser_id.size() ; i++){
            if(visit[i]) continue; // 이미 선택된 id일 경우 continue

            for(int j = 0 ; j < stars[depth].size() ; j++){ // 모든 별(*) 문자를 비교 대상 user_id의 문자로 변경
                cur[stars[depth][j]] = guser_id[i][stars[depth][j]];
            }

            if(cur == guser_id[i]){ // 변경된 문자열이 user_id와 일치할 경우 조합이 가능함
                visit[i] = true;
                dfs(depth + 1);
                visit[i] = false;
            }
        }
        
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    guser_id = user_id;
    gbanned_id = banned_id;
    for(string bid : banned_id){
        int pos = -1;
        vector<int> tmp;
        while((pos = bid.find("*", pos + 1)) != string::npos){ // 모든 banned_id의 별(*) 인덱스 기록
            tmp.push_back(pos);
        }
        stars.push_back(tmp);
    }
    dfs(0);
    
    return answer.size();
}