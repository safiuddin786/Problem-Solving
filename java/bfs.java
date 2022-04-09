import java.util.*;

public class bfs {
    int vertices;
    int adjMat[][];

    bfs() {
        vertices = 8;
        adjMat = new int[][] { { 0, 1, 1, 0, 0, 0, 0, 0 }, { 1, 0, 0, 1, 1, 0, 0, 0 }, { 1, 0, 0, 0, 0, 1, 1, 0 },
                { 0, 1, 0, 0, 0, 0, 0, 1 }, { 0, 1, 0, 0, 0, 0, 0, 1 }, { 0, 0, 1, 0, 0, 0, 0, 1 },
                { 0, 0, 1, 0, 0, 0, 0, 1 }, { 0, 0, 0, 1, 1, 1, 1, 0 } };
    }

    void check(int s) {
        int visited[] = new int[vertices];
        int i = s;
        Queue<Integer> q = new LinkedList<Integer>();
        visited[i] = 1;
        System.out.print(i + " ");
        q.add(s);
        while (!q.isEmpty()) {
            i = q.remove();
            for (int j = 0; j < vertices; j++) {
                if (adjMat[i][j] == 1 && visited[j] == 0) {
                    System.out.print(j + " ");
                    visited[j] = 1;
                    q.add(j);
                }
            }
        }
    }

    public static void main(String args[]) {
        bfs b = new bfs();
        System.out.println("Output of bfs is :");
        b.check(0);
    }
}