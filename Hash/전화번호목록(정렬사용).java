import java.util.Arrays;

class Solution {
    public boolean solution(String[] phone_book) {
        Arrays.sort(phone_book);
        int size = phone_book.length-1;
        for(int i=0; i<size; i++){
            if(phone_book[i+1].startsWith(phone_book[i]))
                return false;
        }
        return true;
    }
}
