import java.util.*;
import java.io.*;

public class mwc15c4p3{
  public static void main(String[] args) throws IOException{
    BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    
    String[] line = in.readLine().split(" ");
    
    int N = Integer.parseInt(line[0]), Q = Integer.parseInt(line[1]);;
    HashSet<Long> hs = new HashSet<Long>();
    final int BIG = 2 * 1000 * 1000 * 1000;
    
    HashMap<Integer, Integer> xmap = new HashMap<Integer, Integer>();
    HashMap<Integer, Integer> ymap = new HashMap<Integer, Integer>();
    
    for(int i = 0; i < N; i++){
      line = in.readLine().split(" ");
      int x = Integer.parseInt(line[0]), y = Integer.parseInt(line[1]);
      
      hs.add((long) x * BIG + y);
      
      if(xmap.containsKey(x)){
        int oldValue = xmap.get(x);
        xmap.put(x, oldValue + 1);
      }
      else
        xmap.put(x, 1);
      
      if(ymap.containsKey(y)){
        int oldValue = ymap.get(y);
        ymap.put(y, oldValue + 1);
      }
      else
        ymap.put(y, 1);
    }
    
    for(int i = 0; i < Q; i++){
      line = in.readLine().split(" ");
      int type = Integer.parseInt(line[0]);
      
      if(type == 1){
        int x = Integer.parseInt(line[1]), y = Integer.parseInt(line[2]);
        
        if(hs.contains((long) x * BIG + y))
          System.out.println("salty");
        else
          System.out.println("bland");
      }
      else{
        String subtype = line[1];
        
        if(subtype.equals("X")){
          int x = Integer.parseInt(line[2]);
          if(xmap.containsKey(x))
            System.out.println(xmap.get(x));
          else
            System.out.println(0);
        }
        else{
          int y = Integer.parseInt(line[2]);
          if(ymap.containsKey(y))
            System.out.println(ymap.get(y));
          else
            System.out.println(0);
        }
      }
    }
  }
}