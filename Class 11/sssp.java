import java.util.*;

public class sssp{
  public static void main(String[] args){
    Scanner in = new Scanner(System.in);
    
    ArrayList<Edge>[] adj = new ArrayList[1001];
    
    int N = in.nextInt(), M = in.nextInt();
    for(int i = 1; i <= N; i++)
      adj[i] = new ArrayList<Edge>();
    
    for(int i = 0; i < M; i++){
      int from = in.nextInt(), to = in.nextInt(), weight = in.nextInt();
      adj[from].add(new Edge(to, weight));
      adj[to].add(new Edge(from, weight));
    }
    
    PriorityQueue<Edge> heap = new PriorityQueue<Edge>();
    int[] dist = new int[1001];
    
    for(int i = 2; i <= N; i++)
      dist[i] = 20 * 1000 * 1000;
    
    heap.offer(new Edge(1, 0));
    
    while(!heap.isEmpty()){
      int cur = heap.poll().to;
      
      for(Edge neigh : adj[cur]){
        if(dist[cur] + neigh.wt < dist[neigh.to]){
          dist[neigh.to] = dist[cur] + neigh.wt;
          heap.offer(new Edge(neigh.to, dist[neigh.to]));
        }
      }
    }
    
    for(int i = 1; i <= N; i++){
      if(dist[i] < 20 * 1000 * 1000)
        System.out.println(dist[i]);
      else
        System.out.println(-1);
    }
  }
}

class Edge implements Comparable<Edge>{
  int to, wt;
  public Edge(int t, int w){
    to = t;
    wt = w;
  }
  public int compareTo(Edge other){
    return wt - other.wt;
  }
}