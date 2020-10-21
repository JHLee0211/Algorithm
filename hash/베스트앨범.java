import java.util.HashMap;
import java.util.Map;
import java.util.LinkedList;
import java.util.Collections;
import java.util.PriorityQueue;

class Solution {
    public static HashMap<String, Integer> sortMapByValue(Map<String, Integer> map){
        LinkedList<Map.Entry<String, Integer>> entries = new LinkedList<>(map.entrySet());
        Collections.sort(entries, (o1, o2) -> o1.getValue().compareTo(o2.getValue()));
        
        HashMap<String, Integer> result = new HashMap<>();
        for(Map.Entry<String, Integer> entry: entries){
            result.put(entry.getKey(), entry.getValue());
        }
        return result;
    }
    
    public int[] solution(String[] genres, int[] plays) {
        int[] answer = {};
        LinkedList<Integer> ans = new LinkedList<>();
        int length = genres.length;
        
        HashMap<String, Integer> sum = new HashMap<>();
        HashMap<String, PriorityQueue<int[]>> num = new HashMap<>();
        for(int i=0; i<length; i++){
            sum.put(genres[i], sum.getOrDefault(genres[i], 0)+plays[i]);
            if(!num.containsKey(genres[i])){
                num.put(genres[i], new PriorityQueue<int[]>(
                    (a, b) -> {return b[1] - a[1];}
                ));
            }
            num.get(genres[i]).add(new int[]{i, plays[i]});
        }
        sum = sortMapByValue(sum);
        for(Map.Entry<String, Integer> m: sum.entrySet()){
            PriorityQueue<int[]> pq = num.get(m.getKey());
            int n = 0;
            while(!pq.isEmpty() && n < 2){
                ans.add(pq.poll()[0]);
                n++;
            }
        }
        int aSize = ans.size();
        answer = new int[aSize];
        for(int i=0; i<aSize; i++){
            answer[i] = ans.get(i);
        }
        return answer;
    }
}