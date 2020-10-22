#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> gpnum;
    map<string, vector<pair<int,int>>> gidx;
    
    for(int i = 0; i < plays.size(); i++) {
        if(gpnum.find(genres[i]) == gpnum.end()) {
            gpnum[genres[i]] = 0;
        }
        gpnum[genres[i]] += plays[i];
        gidx[genres[i]].push_back(make_pair(plays[i], i * -1));
    }
    
    vector<pair<int, string>> v;
    for(auto g : gpnum) {
        v.push_back(make_pair(g.second, g.first));
    }
    
    sort(v.begin(), v.end(), greater<pair<int,string>>());
    
    for(auto x : v) {
        string genre = x.second;
        sort(gidx[genre].begin(), gidx[genre].end());
        answer.push_back(gidx[genre].back().second * -1);
        if(gidx[genre].size() != 1) {
            gidx[genre].pop_back();
            answer.push_back(gidx[genre].back().second * -1);
        }
    }
    
    /*for(auto genre : v) {
        sort(gidx[genre.first].begin(), gidx[genre.first].end());
        answer.push_back(gidx[genre.first].back().second * -1);
        if(gidx[genre.first].size() != 1) {
            gidx[genre.first].pop_back();
            answer.push_back(gidx[genre.first].back().second * -1);
        }
    }*/
    
    return answer;
}