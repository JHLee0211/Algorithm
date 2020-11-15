#include <vector>
#include <algorithm>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<vector<int>> data) {
    int answer = 0;
    sort(data.begin(), data.end());
    for(int i = 0; i < data.size() - 1; i++) {
        for(int j = i + 1; j <  data.size(); j++) {
            if(data[i][0] == data[j][0] || data[i][1] == data[j][1])
                continue;
            int lr, lc, sr, sc;
            sr = data[i][0];   
            lr = data[j][0];
            if(data[i][1] < data[j][1]) {
                lc = data[j][1];
                sc = data[i][1];
            }
            else {
                lc = data[i][1];
                sc = data[j][1];
            }
                
            bool canuse = true;
            for(int k = i + 1; k < j && canuse; k++) {
                if(data[k][0] == sr || data[k][0] == lr)
                    continue;
                if(data[k][1] > sc && data[k][1] < lc)
                    canuse = false;
            }
            
            if(canuse) {
                answer++;
            }
        }
    }
    
    return answer;
}