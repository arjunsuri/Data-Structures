import java.util.Iterator;
import java.util.LinkedList;

public class DepthFirstTraversal {

    private final int V;
    private final LinkedList<Integer> adj[];

    public DepthFirstTraversal(int v) {
        V = v;
        adj = new LinkedList[v];
        for (int i = 0; i < v; i++) {
            adj[i] = new LinkedList();
        }
    }

    void addEdge(int v, int w) {
        adj[v].add(w);
    }

    void depthFirstSearch(final int startVertex, final boolean visited[]) {
        visited[startVertex] = true;
        System.out.print(startVertex + " ");
        final Iterator<Integer> iterator = adj[startVertex].listIterator();
        while(iterator.hasNext()) {
            final int n = iterator.next();
            if(!visited[n]) {
              depthFirstSearch(n, visited);
            }
        }
    }

    public static void main(String args[]) {
        final DepthFirstTraversal depthFirstTraversal = new DepthFirstTraversal(4);
        depthFirstTraversal.addEdge(0, 1);
        depthFirstTraversal.addEdge(0, 2);
        depthFirstTraversal.addEdge(1, 2);
        depthFirstTraversal.addEdge(2, 0);
        depthFirstTraversal.addEdge(2, 3);
        depthFirstTraversal.addEdge(3, 3);
        final boolean visited[] = new boolean[4];
        System.out.println("Following is Depth First Traversal starting from vertex 2:-");
        depthFirstTraversal.depthFirstSearch(2, visited);
    }
}
