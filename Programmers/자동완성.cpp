/*
 - https://programmers.co.kr/learn/courses/30/lessons/17685
*/
#include <string>
#include <vector>
using namespace std;

typedef struct Trie{
    bool isleaf;
    int nleaf;
    Trie * leaf[26];
    Trie(){
        isleaf = false; nleaf = 0;
        for(int i = 0 ; i < 26 ; i++) leaf[i] = NULL;
    }
}Trie;

void push(Trie * root, string word){
    Trie * ptr = root;
    for(int i = 0 ; i < word.size() ; i++){
        if(ptr->leaf[(word[i]-'a')] == NULL){
            ptr->leaf[(word[i]-'a')] = new Trie();
        };
        ptr = ptr->leaf[(word[i])-'a'];
        ptr->nleaf++;
    }
    ptr->isleaf = true;
}

int find_minimum(Trie * root, string word){
    int cnt = 0;
    Trie * ptr = root;
    for(int i = 0 ; i < word.size() ; i++){
        if(ptr->nleaf == 1) break;
        ptr = ptr->leaf[(word[i]-'a')];
        cnt++;
    }
    return cnt;
}

int solution(vector<string> words) {
    int answer = 0;
    Trie root;
    for(string word : words){
        push(&root, word);
    }
    for(string word : words){
        answer += find_minimum(&root, word);
    }
    
    return answer;
}