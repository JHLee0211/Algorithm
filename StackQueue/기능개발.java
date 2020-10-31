import java.util.ArrayList;
import java.util.LinkedList;

class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        int[] days = new int[progresses.length];
        
        for(int i=0; i<progresses.length; i++){
            days[i] = (99 - progresses[i]) / speeds[i] + 1;
        }
        
        ArrayList<Integer> list = new ArrayList<>();
        LinkedList<Integer> q = new LinkedList<>();
        
        
        for(int i=0; i<days.length; i++){
            if(!q.isEmpty() && days[i] > q.peek()) {
                list.add(q.size());
                q.clear();
            }
            q.offer(days[i]);
        }
        list.add(q.size());
        q.clear();
        
        int size = list.size();
        int[] answer = new int[size];
        for(int i=0; i<size; i++){
            answer[i] = list.get(i);
        }
        return answer;
    }
}