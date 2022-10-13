import java.util.HashMap;
import java.util.Map;

public class GoodPairs {
    public static void main(String[] args) {
        int N=9;
        int M=3;
        int K=2;
        int A[] = new int[]{1,2,3,1,2,3,2,1,2};

        Map<Integer, Integer> table = new HashMap<>();
        for(int i=0; i<N; i++){
            if(table.containsKey(A[i])){
                table.put(A[i], table.get(A[i])+1);
            }else{
                table.put(A[i], 1);
            }
        }

        for(int i=0; i<N; i++){
            int modifier = 0;
            if(i-1 >= 0){
                if(table.get(A[i]) == 1){
                    table.remove(A[i]);
                    modifier = 1;
                }else{
                    table.put(A[i], table.get(A[i])-1);
                }
            }
            Map<Integer, Integer> temp = Map.copyOf(table);
            for(int j=N-1; j>=i; j--){
                if(j < N-1){
                    if(temp.get(A[i]) == 1){
                        temp.remove(A[i]);
                    }else{
                        temp.put(A[i], temp.get(A[i])-1);
                    }
                }
                int distinctElements = temp.size();
                if(distinctElements >= K*M){
                    System.out.println(j+1-i);
                    return;
                }
            }
        }
    }
}
