import java.util.Map;
import java.util.HashMap;

class Solution {
    public int solution(String[][] clothes) {
        int answer = 1;
        HashMap<String, Integer> hm = new HashMap<>();
        for(String[] c: clothes){
            hm.put(c[1], hm.getOrDefault(c[1], 0)+1);
        }
        for(Map.Entry<String, Integer> el: hm.entrySet()){
            answer *= el.getValue()+1;
        }
        answer--;
        return answer;
    }
}