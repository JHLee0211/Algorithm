import java.util.Arrays;
    
class Solution {
    public int[] solution(int[] array, int[][] commands) {
        int[] answer = new int[commands.length];
        int idx = 0;
        for(int[] c: commands){
            int[] tmp = new int[c[1] - c[0] + 1];
            System.arraycopy(array, c[0]-1, tmp, 0, c[1] - c[0] + 1);
            Arrays.sort(tmp);
            answer[idx++] = tmp[c[2]-1];
        }
        return answer;
    }
}