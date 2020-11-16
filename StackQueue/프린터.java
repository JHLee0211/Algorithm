import java.util.LinkedList;

class Solution {
    public int solution(int[] priorities, int location) {
        int answer = 0;
        LinkedList<int[]> q = new LinkedList<>();
        
        for(int i=0; i<priorities.length; i++){
            q.add(new int[] {priorities[i], i});
        }
        
        LinkedList<Integer> work = new LinkedList<>();
        while(!q.isEmpty()){
            int maxIdx = 0;
            int size = q.size();
            for(int i=1; i<size; i++){
                if(q.get(maxIdx)[0] < q.get(i)[0])
                    maxIdx = i;
            }
            
            while(maxIdx-- != 0){
                q.add(q.poll());
            }
            
            work.add(q.poll()[1]);
        }
        
        int wSize = work.size();
        for(int i=0; i<wSize; i++){
            if(work.get(i) == location){
                answer = i+1;
                break;
            }
        }
        
        return answer;
    }
}