import java.util.ArrayList;

class Solution {
    public int r;
    public int n;
    public boolean[] notPrime;
    public boolean[] selected;
    public ArrayList<Character> chars = new ArrayList<>();
    public int answer = 0;
    char[] nums;
    
    public void perm(int cnt, int select){
        if(cnt == r){
            int tmp = 0;
            for(char c: chars){
                tmp *= 10;
                tmp += c-'0';
            }
            if(!selected[tmp] && !notPrime[tmp]) {
                answer++;
                selected[tmp] = true;
            }
            return;
        }
        for(int i=0; i<n; i++){
            if((select & 1<<i) == 0){
                select |= 1<<i;
                chars.add(nums[i]);
                perm(cnt+1, select);
                chars.remove(chars.size()-1);
                select &= ~(1<<i);
            }
        }
    };
    
    public int solution(String numbers) {
        n = numbers.length();
        int primeMax = (int)Math.pow(10, n+1);
        notPrime = new boolean[primeMax+1];
        selected = new boolean[primeMax+1];
        notPrime[0] = true;
        notPrime[1] = true;
        for(int i=2; i*i <= primeMax; i++){
            if(!notPrime[i]){
                for(int j=2*i; j<= primeMax; j+=i){
                    notPrime[j] = true;
                }
            }
        }
        
        nums = numbers.toCharArray();
        
        for(int i=1; i<=n; i++){
            r = i;
            perm(0, 0);
        }
        return answer;
    }
}