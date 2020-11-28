/*
 - https://programmers.co.kr/learn/courses/30/lessons/42888
*/
#include <string>
#include <vector>
#include <sstream>
#include <map>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<string> uidvec;
    map<string, string> uidmap;
    string status, uid, name;
    for(string rec : record){
        stringstream ss(rec);
        ss >> status >> uid >> name;
        if(status == "Enter"){
            // uid가 map에 있으면 map uid 갱신
            if(uidmap.find(uid) != uidmap.end()){
                uidmap.erase(uid);
            }
            uidmap.insert(make_pair(uid, name));
        
            uidvec.push_back(uid);
            answer.push_back("님이 들어왔습니다.");
        }
        else if(status == "Change"){
            if(uidmap.find(uid) != uidmap.end()){
                uidmap.erase(uid);
            }
            uidmap.insert(make_pair(uid, name));
        }
        else{
            uidvec.push_back(uid);
            answer.push_back("님이 나갔습니다.");
        }
    }
    
    for(int i = 0 ; i < uidvec.size() ; i++){
        answer[i] = uidmap.find(uidvec[i])->second + answer[i];
    }
    
    return answer;
}