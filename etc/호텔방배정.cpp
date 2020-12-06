#include <string>
#include <vector>
#include <map>
using namespace std;
map<long long, long long> m;

long long find(long long room) {
    if(m[room] == 0) {
        return room;
    }
    
    return m[room] = find(m[room]);
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    
    for(auto cur : room_number){
        long long room = find(cur);
        answer.push_back(room);
        m[room] = room + 1;
    }
    
    return answer;
}