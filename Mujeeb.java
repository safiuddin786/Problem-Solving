public class Mujeeb {
    public static void main(String args[]) {
        boolean second = false;
        int maximum = Integer.MIN_VALUE;
        int second_max = Integer.MIN_VALUE;
        int[] a = new int[2];
        a[0] = Integer.MIN_VALUE;
        a[1] = Integer.MAX_VALUE+1;
        for(int i=0; i<2; i++){
            if(a[i] > maximum) maximum = a[i];
        }
        for(int i=0; i<2; i++){
            if(a[i] > second_max && a[i] != maximum){
                second = true;
                second_max = a[i];
            }
        }
        System.out.println(second_max);
    }
}