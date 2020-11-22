/*
 - https://programmers.co.kr/learn/courses/30/lessons/17684
*/
#include <string>
#include <vector>
using namespace std;

typedef struct Trie{
    int index;
    Trie * leaf[26];
    Trie(){
        index = 0;
        for(int i = 0 ; i < 26 ; i++) leaf[i] = NULL;
    }
}Trie;

int find_idx(Trie * root, string target){ // "AB"
    Trie * ptr = root;
    for(int i = 0 ; i < target.size() ; i++){
        if(ptr->leaf[target[i] - 'A'] == NULL){
            return 0;
        }
        ptr = ptr->leaf[target[i] - 'A'];
    }
    return ptr->index;
}

void push(Trie * root, string target, int idx){
    Trie * ptr = root;
    for(int i = 0 ; i < target.size() ; i++){
        if(ptr->leaf[target[i]-'A'] == NULL){
            ptr->leaf[target[i]-'A'] = new Trie();
        }
        ptr = ptr->leaf[target[i]-'A'];
    }
    ptr->index = idx;
}

vector<int> solution(string msg) {
    vector<int> answer;
    int new_index = 27;
    Trie root;
    for(int i = 0 ; i < 26 ; i++){
        root.leaf[i] = new Trie();
        root.leaf[i]->index = i + 1;
    }
    
    for(int start = 0 ; start < msg.size() ; start++){
        string target, plus;
        int idx;

        for(int len = 1 ; len <= msg.size() - start ; len++){
            target = msg.substr(start, len);
            
            idx = find_idx(&root, target);

            if(idx != 0){
                continue;
            }
            else{
                push(&root, target, new_index++);

                target = target.substr(0, target.size() - 1);
                
                idx = find_idx(&root, target);
                break;
            }
        }
        start += target.size() - 1;
        answer.push_back(idx);
    
    }
    
    return answer;
}