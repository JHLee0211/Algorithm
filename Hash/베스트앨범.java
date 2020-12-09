import java.util.HashMap;
import java.util.LinkedHashMap;
import java.util.Map;
import java.util.LinkedList;
import java.util.Collections;
import java.util.PriorityQueue;

class 베스트앨범 {
    public static LinkedHashMap<String, Integer> sortMapByValue(Map<String, int[]> map){
        LinkedList<Map.Entry<String, int[]>> entries = new LinkedList<>(map.entrySet());
        Collections.sort(entries, (o1, o2) -> {
            if(o1.getValue()[1] == o2.getValue()[1])
                return o1.getValue()[0] - o2.getValue()[0];
            return o2.getValue()[1] - o1.getValue()[1];
        });
        LinkedHashMap<String, Integer> result = new LinkedHashMap<>();
        for(Map.Entry<String, int[]> entry: entries){
            result.put(entry.getKey(), entry.getValue()[1]);
        }
        return result;
    }
    
    public int[] solution(String[] genres, int[] plays) {
        int[] answer = {};
        int length = genres.length;
        HashMap<String, int[]> sum = new HashMap<>();
        HashMap<String, LinkedList<int[]>> num = new HashMap<>();
        
        for(int i=0; i<length; i++){
            if(!num.containsKey(genres[i])){
                sum.put(genres[i], new int[]{i,0});
            }
            sum.put(genres[i], new int[] {sum.get(genres[i])[0], sum.get(genres[i])[1]+plays[i]});
            if(!num.containsKey(genres[i])){
                num.put(genres[i], new LinkedList<>());
            }
            num.get(genres[i]).add(new int[]{i, plays[i]});
        }
        LinkedHashMap<String,Integer> sortedSum = sortMapByValue(sum);
        
        LinkedList<Integer> ans = new LinkedList<>();
        for(Map.Entry<String, Integer> m: sortedSum.entrySet()){
            LinkedList<int[]> list = num.get(m.getKey());
            Collections.sort(list, (a, b) -> {
                    if(b[1] == a[1])
                        return a[0]-b[0];
                    return b[1]-a[1];
                });
            ans.add(list.get(0)[0]);
            if(list.size() > 1){
                ans.add(list.get(1)[0]);
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