import java.util.LinkedList;
import java.util.Arrays;

class 프린터2 {
    public int solution(int[] priorities, int location) {
        int answer = 1;
        int idx = location;
        int size = priorities.length;
        LinkedList<Integer> q = new LinkedList<Integer>();
        
        for(int p: priorities){
            q.add(p);
        }
        
        
        Arrays.sort(priorities);
        
        while(true){
            while(priorities[size - answer] != q.peek()){
                q.add(q.poll());
                if(--idx < 0) idx = q.size()-1;
            }
            if(idx == 0) break;
            q.poll();
            if(--idx < 0) idx = q.size()-1;
            answer++;
        }
        
        return answer;
    }
}