#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;

map<string, set<int>> m;
set<string> s;

bool same(string bid, string uid) {
    if(bid.size() != uid.size())
        return false;
    for(int i = 0; i < bid.size(); i++) {
        if(bid[i] != '*' && bid[i] != uid[i])
            return false;
    } 
    return true;
}

void dfs(int lv,  vector<string> banned_id, vector<bool> used) {
    if(lv == banned_id.size()) {
        string str = "";
        for(int i = 0; i < used.size(); i++) {
            if(used[i])
                str += to_string(i);
        }
        s.insert(str);
        return;
    }
    string bid = banned_id[lv];
    for(auto uidx : m[bid]) {
        if(!used[uidx]) {
            used[uidx] = true;
            m[bid].erase(uidx);
            dfs(lv + 1, banned_id, used);
            used[uidx] = false;
            m[bid].insert(uidx);
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    for(auto bid : banned_id) {
        for(int i = 0; i < user_id.size(); i++) {
            string uid = user_id[i];
            if(same(bid, uid)) {
                m[bid].insert(i);
            }
        }
    }
    
    dfs(0, banned_id, vector<bool>(user_id.size(), false));
    return s.size();
}