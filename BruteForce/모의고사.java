import java.util.ArrayList;
    
class Solution {
    public int[] solution(int[] answers) {
        int[] answer = {};
        int highScore = 0;
        int ansSize = answers.length;
        int one = 1;
        int two = 1;
        int[] three = {3, 1, 2, 4, 5};
        int[] score = {0, 0, 0};
        for(int i=0; i<ansSize; i++){
            if(one++ == answers[i]) score[0]++;
            if(i%2 == 0){
                if(2 == answers[i]) score[1]++;
            } else{
                if(two++ == answers[i]) score[1]++;
            }
            if(three[i%10/2] == answers[i]) score[2]++;
            
            if(one > 5) one = 1;
            if(two > 5) two = 1;
            else if(two == 2) two = 3;
        }
        
        for(int i=0; i<3; i++){
            if(highScore < score[i])
                highScore = score[i];
        }
        
        ArrayList<Integer> list = new ArrayList<>();
        for(int i=0; i<3; i++){
            if(highScore == score[i])
                list.add(i+1);
        }
        
        int listSize = list.size();
        answer = new int[listSize];
        for(int i=0; i<listSize; i++){
            answer[i] = list.get(i);
        }
        
        return answer;
    }
}