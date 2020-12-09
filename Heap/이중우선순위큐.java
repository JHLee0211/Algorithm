import java.util.PriorityQueue;

class 이중우선순위큐 {
    public int[] solution(String[] operations) {
        int[] answer = {0, 0};
        PriorityQueue<Integer> ascend = new PriorityQueue<Integer>();
        PriorityQueue<Integer> descend = new PriorityQueue<Integer>((a, b) -> {
            return b - a;
        });
        
        for(String s: operations){
            if(s.charAt(0) == 'I'){
                int tmp = Integer.parseInt(s.substring(2));
                ascend.add(tmp);
                descend.add(tmp);
            } else{
                if(s.charAt(2) == '1'){
                    ascend.remove(descend.poll());
                } else{
                    descend.remove(ascend.poll());
                }
            }
        }
        
        if(!ascend.isEmpty()){
            answer[0] = descend.poll();
            answer[1] = ascend.poll();
        }
        
        return answer;
    }
}