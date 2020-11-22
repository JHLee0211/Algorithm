/*
 - https://programmers.co.kr/learn/courses/30/lessons/17686
*/
#include <string>
#include <vector>
#include <algorithm>
#define ISNUM(c) (c <= '9' && c >= '0')
using namespace std;

typedef struct File{
    int idx;
    string name;
    string head;
    int number;
    string tail;
    bool operator < (const File& file) const
    {
        string src = head;
        string des = file.head;
        transform(src.begin(), src.end(), src.begin(), ::toupper);
        transform(des.begin(), des.end(), des.begin(), ::toupper);
        
        if(src != des) return src < des;
        if(number != file.number) return number < file.number;
        
        return idx < file.idx;
    }
}File;


vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<File> newfiles;
    int fcount = 0;
    for(string file : files){
        fcount++;
        int numidx = 0x7fffffff, numlen;
        for(int i = 0 ; i < 10 ; i++){
            int idx = file.find(to_string(i));
            if(idx != string::npos && numidx > idx) {
                numidx = idx;
                int p = idx + 1; // 숫자 시작 바로 다음 위치부터 숫자의 길이 파악
                while(p < file.size() && ISNUM(file[p])){
                    p++;
                }
                numlen = p - idx;
            }
        }
        File finfo;
        finfo.idx = fcount;
        finfo.name = file;
        finfo.head = file.substr(0, numidx);
        finfo.number = stoi(file.substr(numidx, numlen));
        finfo.tail = file.substr(numidx + numlen, file.size() - (numidx + numlen));
        newfiles.push_back(finfo);
    }
    
    sort(newfiles.begin(), newfiles.end());
    
    for(File file : newfiles){
        answer.push_back(file.name);
    }
    
    return answer;
}