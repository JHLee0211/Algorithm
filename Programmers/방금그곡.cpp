/*
 - https://programmers.co.kr/learn/courses/30/lessons/17683
 - 12, 15 테케... 조심
*/
#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    int playtime = 0;
    for(string minfo : musicinfos){
        stringstream ss(minfo);
        string start_t, end_t, title, lyrics;
        getline(ss, start_t, ',');
        getline(ss, end_t, ',');
        getline(ss, title, ',');
        getline(ss, lyrics, ',');
        
        int hour = stoi(end_t.substr(0, 2)) - stoi(start_t.substr(0,2));
        int min = stoi(end_t.substr(3, 2)) - stoi(start_t.substr(3, 2));
    
        min += hour * 60;
        
        int len = 0;
        for(int i = 0 ; i < lyrics.size() ; i++){
            if(lyrics[i] == '#') continue;
            len++;
        }
        
        int share = min / len;
        int remainder = min % len;
        
        string full_lyrics;
        for(int i = 0 ; i < share ; i++) full_lyrics += lyrics;
        //full_lyrics += lyrics.substr(0, remainder); // 12, 15 테스트케이스 에러..
        for(int i = 0 ; i < remainder ; i++){
            if(lyrics[i] == '#') remainder++;
            full_lyrics += lyrics[i];
        }
        
        int pos = 0;
        while(full_lyrics.find(m, pos) != string::npos){
            int idx = full_lyrics.find(m, pos);
            if(full_lyrics[idx + m.size()] != '#') {
                answer = min > playtime ? title : answer;
                playtime = min > playtime ? min : playtime;
            }
            pos = idx + m.size();
        }    
    }
    return answer;
}