class Solution {
    private boolean check(int []arr1,int[]arr2){
        for(int i=0;i<128;i++){
            if(arr2[i]<arr1[i]) return false;
        }
        return true;
    }
    public String minWindow(String s, String t) {
        String ans ="";
        int length=Integer.MAX_VALUE;
        int [] tarr = new int[128];
        int sarr[] = new int[128];
        for(int i=0;i<t.length();i++){
            tarr[t.charAt(i)]++;
        }
        int i=0;
        int j=0;
        int n =s.length();
        while(j<n){
            char ch =s.charAt(j);
            sarr[ch]++;
            while(check(tarr,sarr)){
                if(length>j-i+1){
                    length= j-i+1;
                    ans = s.substring(i,j+1);
                }
                char sh = s.charAt(i);
                sarr[sh]--;
                i++;
            }
            j++;
        }
        return ans;

    }
}