import java.util.Arrays;
import java.util.PriorityQueue;

class Solution {
    public int solution(int[][] jobs) {
        int answer = 0;
        
        Arrays.sort(jobs, (a, b) -> {
                return Integer.compare(a[0], b[0]);
            }
        );
        
        int endTime = 0;
        int idx = 0;
        PriorityQueue<int[]> candi = new PriorityQueue<int[]>((a, b) -> {
            return Integer.compare(a[1], b[1]);
        });
        while(idx < jobs.length || !candi.isEmpty()) {
            while(idx < jobs.length && jobs[idx][0] <= endTime) {
                candi.add(jobs[idx]);
                idx++;
            }
            if(!candi.isEmpty()){
                int[] c = candi.poll();
                answer += endTime + c[1] - c[0];
                endTime += c[1];
            } else{
                endTime = jobs[idx][0];
            }
        }
        
        answer /= jobs.length;
        
        return answer;
    }
}