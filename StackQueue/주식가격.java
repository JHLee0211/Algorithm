import java.util.Stack;

class Solution {
    public int[] solution(int[] prices) {
        int[] answer = new int[prices.length];
        Stack<Integer> stk = new Stack<>();
        stk.push(0);
        for(int i=1; i<prices.length; i++){
            while(!stk.isEmpty() && prices[stk.peek()] > prices[i]){
                answer[stk.peek()] = i - stk.peek();
                stk.pop();
            }
            stk.push(i);
        }
        while(!stk.isEmpty()){
            answer[stk.peek()] = prices.length - stk.peek() - 1;
            stk.pop();
        }
        return answer;
    }
}