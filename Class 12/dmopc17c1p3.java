import java.io.*;
import java.util.*;

public class dmopc17c1p3{
  public static void main(String[] args) throws IOException{
    BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    
    String[] s = in.readLine().split(" ");
    int N = Integer.parseInt(s[0]), M = Integer.parseInt(s[1]);
    
    ArrayList<Pair>[] adj = new ArrayList[N + 1];
    for(int i = 1; i <= N; i++)
      adj[i] = new ArrayList<Pair>();
    
    for(int i = 0; i < M; i++){
      s = in.readLine().split(" ");
      int u = Integer.parseInt(s[0]), v = Integer.parseInt(s[1]), w = Integer.parseInt(s[2]);
      adj[u].add(new Pair(v, w));
      adj[v].add(new Pair(u, w));
    }
    
    // first = # of total roads
    // second = # of dangerous roads
    // third = which node
    // (first, second) is the distance
    PriorityQueue<Triple> heap = new PriorityQueue<Triple>();
    heap.offer(new Triple(0, 0, 1));
    Pair[] dist = new Pair[N + 1];
    dist[1] = new Pair(0, 0);
    final int INF = 1000 * 1000 * 1000;
    for(int i = 2; i <= N; i++)
      dist[i] = new Pair(INF, INF);
    
    while(!heap.isEmpty()){
      int cur = heap.poll().third;
      for(Pair p : adj[cur]){
        int to = p.first, dang = p.second;
        
        // if dist[cur] + wt < dist[to]
        // tmp = dist[cur] + wt
        
        Pair tmp = dist[cur];
        if(dang == 1){
          tmp.first += 1;
          tmp.second += 1;
        }
        else
          tmp.first += 1;
        
        if(tmp.compareTo(dist[to]) < 0){
          dist[to] = tmp;
          heap.offer(new Triple(dist[to].first, dist[to].second, to));
        }
      }
    }
    
    if(dist[N].first == INF && dist[N].second == INF){
      System.out.println(-1);
    }
    else{
      System.out.println(dist[N].second + " " + dist[N].first);
    }
  }
}

class Pair implements Comparable<Pair>{
  int first, second;
  public Pair(int f, int s){
    first = f;
    second = s;
  }
  
  public int compareTo(Pair other){
    if(first == other.first)
      return second - other.second;
    return first - other.first;
  }
}

class Triple implements Comparable<Triple>{
  int first, second, third;
  public Triple(int f, int s, int t){
    first = f;
    second = s;
    third = t;
  }
  
  public int compareTo(Triple other){
    if(first == other.first)
      return second - other.second;
    return first - other.first;
  }
}