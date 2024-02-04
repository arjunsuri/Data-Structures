import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class BreadthFirstSearchForDisconnectedGraph {

    private static HashMap<Integer, LinkedList<Integer>> graph = new HashMap<>();

    public static void addEdge(int a, int b) {
        final LinkedList<Integer> l;
        if(graph.containsKey(a)) {
            l = graph.get(a);
        } else {
            l = new LinkedList<>();
        }
        l.add(b);
        graph.put(a,l);
    }

    public static void bfshelp(int s, final List<Boolean> visited) {
        final LinkedList<Integer> q = new LinkedList<>();
        q.add(s);
        visited.set(s,true);
        while(!q.isEmpty()) {
            int f=q.poll();
            System.out.print(f+" ");
            if(graph.containsKey(f)) {
                final Iterator<Integer> i = graph.get(f).listIterator();
                while(i.hasNext()) {
                    int n = i.next();
                    if(!visited.get(n)) {
                        visited.set(n,true);
                        q.add(n);
                    }
                }
            }
        }
    }

    public static void bfs(int vertex) {
        final List<Boolean> visited = IntStream.range(0, vertex)
                .mapToObj(i -> false)
                .collect(Collectors.toList());

        IntStream.range(0, vertex)
                .filter(i -> !visited.get(i))
                .forEach(i -> bfshelp(i, visited));
    }

    public static void main(String[] args) {
        int v = 5;
        addEdge(0, 4);
        addEdge(1, 2);
        addEdge(1, 3);
        addEdge(1, 4);
        addEdge(2, 3);
        addEdge(3, 4);
        bfs(v);
    }
}