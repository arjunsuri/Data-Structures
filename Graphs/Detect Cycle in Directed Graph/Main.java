import java.util.*;

public class Main {
    // Methods must be defined at the class level, not inside main()
    public boolean isCyclicUtil(ArrayList<ArrayList<Integer>> adj, int curr,
                                boolean[] visited, boolean[] recStack) {

        visited[curr] = true;
        recStack[curr] = true; // Mark as part of the current recursion path

        for (int neighbor : adj.get(curr)) {
            if (!visited[neighbor]) {
                // Recursive call for unvisited neighbor
                if (isCyclicUtil(adj, neighbor, visited, recStack))
                    return true;
            } else if (recStack[neighbor]) {
                // If the neighbor is already in the recursion stack, we found a cycle
                return true;
            }
        }

        // Backtrack: remove the vertex from recursion stack before returning
        recStack[curr] = false;
        return false;
    }

    public boolean isCyclic(int V, int[][] edges) {
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < V; i++) {
            adj.add(new ArrayList<>());
        }

        for (int[] edge : edges) {
            adj.get(edge[0]).add(edge[1]);
        }

        boolean[] visited = new boolean[V];
        boolean[] recStack = new boolean[V];

        // Check each component (important for disconnected graphs)
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (isCyclicUtil(adj, i, visited, recStack))
                    return true;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        Main solver = new Main();
        int V = 4;
        int[][] edges = {{0, 1}, {1, 2}, {2, 3}, {3, 1}}; // Cycle: 1->2->3->1

        System.out.println("Contains Cycle: " + solver.isCyclic(V, edges));
    }
}