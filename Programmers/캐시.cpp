/*
 - https://programmers.co.kr/learn/courses/30/lessons/17680
*/
#include <string>
#include <vector>
#include <set>
#include <queue>

using namespace std;
typedef struct Item{
    string city;
    int timestamp;
    Item(string c, int t){
        city = c;
        timestamp = t;
    }
}Item;
bool operator<(Item a, Item b) {
	return a.timestamp > b.timestamp;
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    if(cacheSize == 0) return cities.size() * 5;
    // set, pq 동시 사용
    // pq에 있는 아이템들의 목록을 set으로 관리
    // set에 없을 경우 pq에서 하나 pop 해주고, pop된 item을 set에서 제거
        // 새로운 item을 현재 timestamp 기준으로 pq에 push, set에도 추가
    // set에 있을 경우 hit
        // pq에 있는걸 모두 pop해서 해당 item의 timestamp 갱신 후 모두 다시 pq 만들어야 함
    set<string> cache;
    priority_queue<Item> pq_cache, pq_tmp;
    for(string city : cities){
        for(int i = 0 ; i < city.size() ; i++){
            city[i] = toupper(city[i]);
        }

        if(cache.find(city) != cache.end()){ // hit일 경우   
            while(pq_cache.size()){// pq에서 다 꺼냄
                Item item = pq_cache.top();
                pq_cache.pop();
                if(item.city == city){ // hit한 item일 경우 timestamp 갱신
                    item.timestamp = answer;    
                }
                pq_tmp.push(item);
            }
            pq_cache = pq_tmp;
            pq_tmp = {};
            answer += 1;
        }else if(cache.size() < cacheSize){ // 캐시가 아직 다 차지 않았을 경우
            cache.insert(city);
            pq_cache.push(Item(city, answer));
            answer += 5;
        }
        else{// miss일 경우 // pq에서 pop, set에서 삭제 후 item 만들어서 pq, set에 삽입
            Item pop_item = pq_cache.top();
            pq_cache.pop();                 // pq에서 삭제
            cache.erase(pop_item.city);     // set에서 삭제
            
            cache.insert(city);                   // set에 새로운 아이템 삽입
            pq_cache.push(Item(city, answer));   // pq에 새로운 아이템 삽입
            answer += 5;
        }
    }
    
    return answer;
}