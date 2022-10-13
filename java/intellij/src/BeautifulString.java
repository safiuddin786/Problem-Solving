public class BeautifulString {
    public static void main(String[] args) {
        int n=2;
        String s = "01";
        int k = 1;

        int dp[] = new int[n];
        int allZeros = 0;
        for(int i=0; i<n; i++){
            if(s.charAt(i) == '1'){
                allZeros++;
                if(i-k >= 0){
                    if(s.charAt(i-k) == '0')
                        dp[i-k] = 1;
                }
                if(i+k < n){
                    if(s.charAt(i+k) == '0')
                        dp[i+k] = 1;
                }
            }
        }

        int sum=0;
        for(int i=0; i<n; i++)
            sum += dp[i];

        if(sum > allZeros)
            System.out.println(allZeros);
        else
            System.out.println(sum);
    }
}
