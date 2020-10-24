class Solution {
    public int[] solution(int brown, int yellow) {
        int[] answer = new int[2];
        int xy = (brown+4)/2;
        for(int x=1; x<xy; x++){
            int y = xy-x;
            if((x-2)*(y-2) == yellow){
                answer[0] = y;
                answer[1] = x;
                break;
            }
        }
        return answer;
    }
}