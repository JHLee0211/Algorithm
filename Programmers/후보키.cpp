/*
 - https://programmers.co.kr/learn/courses/30/lessons/42890
*/
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
bool compare(vector<int> v1, vector<int> v2){
    if(v1.size() != v2.size()) return v1.size() < v2.size();
    return v1 < v2;
}

bool is_valid(vector<vector<int> > answerList, vector<int> keys){
    //keys에 있는 요소들의 부분집합이 answerList에 있을 때
    for(vector<int> list : answerList){
        //만약 모든 list의 아이템들이 keys에 포함되어 있을 경우 false return
        // keys와 list의 합집합이 keys의 크기와 똑같을 때
        vector<int> union_set = keys;
        for(int i = 0 ; i < list.size() ; i++){
            int size = union_set.size();
            for(int j = 0 ; j < size ; j++){
                if(list[i] == union_set[j]) break;
                else if(j == size - 1){
                    union_set.push_back(list[i]);
                }
            }
        }
        if(union_set.size() == keys.size()) return false;
    }
    return true;
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    int colsize = relation[0].size();
    int arr[8] = {0, 1, 2, 3, 4, 5, 6, 7};
    
    vector<vector<int> > comb;

    for(int i = 0 ; i < (1 << colsize) ; i++){
        vector<int> tmp;
        for(int j = 0 ; j < colsize ; j++){
            if(i & (1 << j))
                tmp.push_back(arr[j]);
        }
        if(tmp.size()) 
            comb.push_back(tmp);
    }
    
    sort(comb.begin(), comb.end(), compare);
    
    vector<vector<int> > answerKey;
    
    for(vector<int> combi : comb){
        if(is_valid(answerKey, combi)){
            set<string> sets;          
            for(vector<string> rel : relation){
                string str;
                for(int c : combi){
                    str += " " + rel[c];
                }
                if(sets.find(str) != sets.end()) break;
                sets.insert(str);
            }
            if(sets.size() == relation.size()){
                answerKey.push_back(combi);
                answer++;
            }
        }   
    }
    return answer;
}