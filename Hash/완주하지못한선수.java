import java.util.HashMap;
import java.util.Map;

class 완주하지못한선수 {
    public String solution(String[] participant, String[] completion) {
        String answer = "";
        HashMap<String, Integer> hm = new HashMap<>();
        for(String p: participant){
                hm.put(p, hm.getOrDefault(p, 0)+1);
        }
        
        for(String c: completion){
            hm.put(c, hm.get(c)-1);
        }
        
        for(Map.Entry<String, Integer> el: hm.entrySet()){
            if(el.getValue() > 0){
                answer = el.getKey();
                break;
            }
        }
        
        return answer;
    }
}