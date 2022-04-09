public class dfs {
    int vertices;
    int adjMat[][];
    int visited[];

    dfs() {
        vertices = 8;
        visited = new int[vertices];
        adjMat = new int[][] { { 0, 1, 1, 0, 0, 0, 0, 0 }, { 1, 0, 0, 1, 1, 0, 0, 0 }, { 1, 0, 0, 0, 0, 1, 1, 0 },
                { 0, 1, 0, 0, 0, 0, 0, 1 }, { 0, 1, 0, 0, 0, 0, 0, 1 }, { 0, 0, 1, 0, 0, 0, 0, 1 },
                { 0, 0, 1, 0, 0, 0, 0, 1 }, { 0, 0, 0, 1, 1, 1, 1, 0 } };
    }

    void check(int s) {
        visited[s] = 1;
        System.out.print(s + " ");
        for (int i = 0; i < vertices; i++) {
            if (adjMat[s][i] == 1 && visited[i] == 0) {
                check(i);
            }
        }
    }

    public static void main(String args[]) {
        dfs b = new dfs();
        System.out.println("Output of dfs is :");
        b.check(0);
    }
}