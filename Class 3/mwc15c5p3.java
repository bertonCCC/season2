import java.util.*;
import java.io.*;

public class mwc15c5p3{
  public static void main(String[] args) throws IOException{
    BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    
    String[] t = in.readLine().split(" ");
    int N = Integer.parseInt(t[0]), M = Integer.parseInt(t[1]);
    
    HashSet<String> hs = new HashSet<String>();
    HashSet<String> ans = new HashSet<String>();
    
    t = in.readLine().split(" ");
    for(int i = 0; i < N; i++){
      hs.add(t[i]);
    }
    
    t = in.readLine().split(" ");
    for(int i = 0; i < M; i++){
      if(hs.contains(t[i]))
        ans.add(t[i]);
    }
    
    System.out.println(ans.size());
  }
}