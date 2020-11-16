import java.util.ArrayList;
import java.util.Collections;
import java.util.PriorityQueue;
    
class Solution {
    public int solution(int[] scoville, int K) {
        int answer = 0;
        PriorityQueue<Integer> pq = new PriorityQueue<Integer>();
        
        for(int s: scoville){
            pq.add(s);
        }
        
        while(pq.peek() < K){
            if(pq.size() == 1){
                answer = -1;
                break;
            }
            
            int tmp = (pq.poll() + pq.poll() * 2);
            pq.add(tmp);
            answer++;
        }
        
        return answer;
    }
}