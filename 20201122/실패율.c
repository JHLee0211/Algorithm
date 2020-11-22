#include <bits/stdc++.h>
using namespace std;
struct xy {
    double error;
    int num;
    bool operator<(const xy &A) const {
        return error == A.error ? num < A.num : error > A.error;
    }
};

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<int> cnt(N + 2), sum(N + 2);
    for (int i = 0; i < stages.size(); i++)
        cnt[stages[i]]++;
    sum[N + 1] = cnt[N + 1];
    for (int i = N; i >= 1; i--)
        sum[i] = cnt[i] + sum[i + 1];

    
    vector<xy> res;
    for (int i = 1; i <= N; i++) {
        if (sum[i] == 0)
            res.push_back({0, i});
        else
            res.push_back({(double)cnt[i] / sum[i], i}); 
    }
    sort(res.begin(),res.end());
    for (int i = 0; i < res.size(); i++)
        answer.push_back(res[i].num);
 
    return answer;
}