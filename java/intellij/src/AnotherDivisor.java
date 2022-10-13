import java.util.Arrays;
import java.util.Scanner;

public class AnotherDivisor {
    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);
        int N = input.nextInt();
        int[] A = new int[N];

        for(int i=0; i<N; i++){
            A[i] = input.nextInt();
        }

        boolean check;

        int count = 0;
        for(int i=0; i<N; i++){
            check = true;
            for(int j=0; j<N; j++){
                if(i != j){
                    if(A[i]%A[j] == 0){
                        check = false;
                        break;
                    }
                }
            }
            if(check){
                count++;
            }
        }
        System.out.println(count);
    }
}
