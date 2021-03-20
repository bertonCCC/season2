import java.util.*;

public class fhc15c1p1{
  public static void main(String[] args){
    Scanner in = new Scanner(System.in);
    
    int T = in.nextInt();
    final int MAX = (int) 1e7; // or = 10 * 1000 * 1000;
    // C++: const int MAX = 1e7
    
    int[] prim = new int[MAX + 1];
    
    for(int i = 2; i <= MAX; i++){
      if(prim[i] == 0){
        for(int j = i; j <= MAX; j += i)
          prim[j] += 1;
      }
    }
    
    for(int t = 1; t <= T; t++){
      int A = in.nextInt(), B = in.nextInt(), K = in.nextInt();
      
      int count = 0;
      
      for(int i = A; i <= B; i++)
        if(prim[i] == K)
          count += 1;
      
      System.out.printf("Case #%d: %d\n", t, count);
      //System.out.println("Case #" + t + ": " + count);
      // C++: printf("Case #%d: %d\n", t, count)
    }
  }
}