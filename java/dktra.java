public class dktra {
    static int dist[];
    int s[];
    static int n;
    int cost[][];
    int maxVal = Integer.MAX_VALUE;

    dktra() {
        n = 6;
        cost = new int[][] { { 0, 50, 45, 10, maxVal, maxVal }, { maxVal, 0, 10, 15, maxVal, maxVal },
                { maxVal, maxVal, 0, maxVal, 30, maxVal }, { 20, maxVal, maxVal, 0, 15, maxVal },
                { maxVal, 20, 35, maxVal, 0, maxVal }, { maxVal, maxVal, maxVal, maxVal, 3, 0 } };
        dist = new int[n];
        for (int i = 0; i < n; i++) {
            dist[i] = maxVal;
        }
        s = new int[n];
    }

    public void minDist() {
        s[0] = 1;
        dist[0] = 0;
        for (int i = 1; i < n; i++) {
            if (cost[0][i] != maxVal) {
                dist[i] = cost[0][i];
            }
        }
        for (int i = 0; i < n; i++) {
            int nextMin = getMin();
            if (nextMin == -1) {
                break;
            }
            s[nextMin] = 1;
            for (int j = 0; j < n; j++) {
                if (cost[nextMin][j] != maxVal && s[j] != 1) {
                    dist[j] = Math.min(dist[nextMin] + cost[nextMin][j], dist[j]);
                }
            }
        }
    }

    public int getMin() {
        int minVal = Integer.MAX_VALUE;
        int minIndex = -1;
        for (int i = 0; i < n; i++) {
            if (dist[i] < minVal && s[i] != 1) {
                minVal = dist[i];
                minIndex = i;
            }
        }
        return minIndex;
    }

    public static void main(String args[]) {
        dktra d = new dktra();
        d.minDist();
        for (int i = 0; i < n; i++) {
            System.out.println(dist[i]);
        }
    }
}
