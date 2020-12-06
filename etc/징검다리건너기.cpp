#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int answer = 0;
void bs(int l, int r, vector<int> stones, int k) {
    if(l > r)
        return;
    int mid = (l + r) / 2;
    int count = 0;
    for(int i = 0; i < stones.size(); i++) {
        if(stones[i] - mid < 0) {
            count++;
            if(count == k) {
                break;
            }
        } 
        else {
            count = 0;
        }
    }
    if(count == k) {
        return bs(l, mid - 1, stones, k);
    }
    else {
        answer = max(answer, mid);
        return bs(mid + 1, r, stones, k);
    }
}

int solution(vector<int> stones, int k) {
    bs(1, 200000000, stones, k);
    return answer;
}