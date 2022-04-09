public class knapsackdp {
    int maxVal(int a, int b) {
        return (a > b) ? a : b;
    }

    int k[][];

    public knapsackdp(int w[], int p[], int c) {
        k = new int[p.length + 1][c + 1];
        for (int i = 0; i <= p.length; i++) {
            for (int j = 0; j <= c; j++) {
                if (i == 0 || j == 0) {
                    k[i][j] = 0;
                } else if (w[i - 1] <= j) {
                    k[i][j] = maxVal(k[i - 1][j - w[i - 1]] + p[i - 1], k[i - 1][j]);
                } else {
                    k[i][j] = k[i - 1][j];
                }
                System.out.print(k[i][j] + " ");
            }
            System.out.println();
        }
    }

    public void traceback(int w[], int p[], int c) {
        int res = k[p.length][c];
        for (int i = p.length; i > 0; i--) {
            if (res == k[i - 1][c]) {
                System.out.println(i - 1 + " = " + 0);
            } else {
                System.out.println(i - 1 + " = " + 1);
                res = res - p[i - 1];
            }
        }
    }

    public static void main(String args[]) {
        int w[] = new int[] { 2, 3, 4 };
        int p[] = new int[] { 1, 2, 5 };
        int c = 6;
        knapsackdp k = new knapsackdp(w, p, c);
        k.traceback(w, p, c);
    }
}
