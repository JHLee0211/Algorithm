 /*
 - https://programmers.co.kr/learn/courses/30/lessons/42891
*/

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct Food{
    long long time;
    int idx;
    Food(long long t, int i){
        time = t;
        idx = i;
    }
    bool operator<(const Food &food)const
    {
        if(time != food.time) return time < food.time;
        return idx < food.idx; 
    }
}Food;

int solution(vector<int> food_times, long long k) {
    int answer = 0;
    long long total = 0;

   vector<Food> sorted;
    
    for(int i = 0 ; i < food_times.size() ; i++){
        sorted.push_back(Food(food_times[i], i));
        total += food_times[i];
    }
    
    if(total <= k){
        answer = -1;
    }
    else{
        int check[200001] = {0}; // i번째가 다 처먹었을 경우 check[i] = 1
        k += 1; // k번째에 먹는걸 찾아야됨    
    
        sort(sorted.begin(), sorted.end());

        long long eated = 0;
        for(int i = 0 ; i < sorted.size() ; i++){
            long long least = sorted[i].time - eated;
            long long remain = (sorted.size() - i);

            if(least * remain < k){
                k -= least * remain;
                eated += least;
                check[sorted[i].idx] = 1;
            }
            else{
                long long cycle = 0;
                while((cycle + 1) * remain < k){
                    cycle++;
                }

                k -= cycle * remain;
                
                int found = 0, index;
                for(index = 0 ; index < food_times.size() ; index++){
                    if(check[index] != 1){
                        found++;
                    }
                    if(found == k) break;
                }

                answer = index + 1;
                break;
            }
        }
    }

    return answer;
}