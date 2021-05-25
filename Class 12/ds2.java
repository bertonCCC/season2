import java.util.*;

public class ds2{
  static int[] parent = new int[100 * 1000 + 1];
  
  static int find(int n){
    if(parent[n] == n) return n;
    return parent[n] = find(parent[n]);
  }
  
  static boolean connected(int u, int v){
    return find(u) == find(v);
  }
  
  static void join(int u, int v){
    int r = find(u), s = find(v);
    if(r != s)
      parent[r] = s;
  }
  
  public static void main(String[] args){
    Scanner in = new Scanner(System.in);
    int N = in.nextInt(), M = in.nextInt();
    
    for(int i = 1; i <= N; i++)
      parent[i] = i;
    
    ArrayList<Integer> answer = new ArrayList<Integer>();
    
    int count = 0;
    for(int i = 1; i <= M; i++){
      int u = in.nextInt(), v = in.nextInt();
      
      if(!connected(u, v)){
        join(u, v);
        count += 1;
        answer.add(i);
      }
      
      if(count == N - 1) break;
    }
    
    if(answer.size() < N - 1)
      System.out.println("Disconnected Graph");
    else{
      for(int n : answer)
        System.out.println(n);
    }
  }
}