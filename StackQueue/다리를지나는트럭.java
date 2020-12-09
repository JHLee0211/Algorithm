import java.util.LinkedList;

class 다리를지나는트럭 {
    public int solution(int bridge_length, int weight, int[] truck_weights) {
        int answer = 0;
        LinkedList<int []> q = new LinkedList<>();
        int sum = 0;
        int idx = 0;
        
        do {
            answer++;
            
            if(!q.isEmpty() && q.peek()[1]+bridge_length == answer){
                sum -= q.poll()[0];
            }
            
            if(idx < truck_weights.length && weight >= sum + truck_weights[idx]){
                sum += truck_weights[idx];
                q.add(new int[] {truck_weights[idx], answer});
                idx++;
            }
            
        } while(!q.isEmpty() || sum != 0);
        
        return answer;
    }
}