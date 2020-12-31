class K번째수 {
    public int[] solution(int[] array, int[][] commands) {
        int[] answer = new int[commands.length];
        int idx = 0;
        for(int[] c: commands){
            int[] tmp = new int[c[1] - c[0] + 1];
            System.arraycopy(array, c[0]-1, tmp, 0, c[1] - c[0] + 1);
            sort(tmp, 0, tmp.length-1);
            answer[idx++] = tmp[c[2]-1];
        }
        return answer;
    }
    
    public void sort(int[] array, int min, int max){
        if(min >= max) return;
        
        int l = min+1;
        int r = max;
        int pivot = array[min];
        
        while(true){
            while(l <=max && array[l] <= pivot){ l++; }
            while(r > min && array[r] >= pivot){ r--; }
            int tmp;
            if(l > r) {
                tmp = array[r];
                array[r] = array[min];
                array[min] = tmp;
                break;
            }
            tmp = array[l];
            array[l] = array[r];
            array[r] = tmp;
        }
        
        sort(array, min, r-1);
        sort(array, r+1, max);
    }
}