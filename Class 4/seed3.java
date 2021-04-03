import java.util.*;

public class seed3{
  public static void main(String[] args){
    Scanner in = new Scanner(System.in);
    int I = in.nextInt(), N = in.nextInt(), J = in.nextInt();
    
    int[] pda = new int[I + 2];
    int[] arr = new int[I + 2];
    
    for(int i = 0; i < J; i++){
      int a = in.nextInt(), b = in.nextInt(), v = in.nextInt();
      
      pda[a] += v;
      pda[b + 1] -= v;
    }
    
    int ans = 0;
    for(int i = 1; i <= I; i++){
      arr[i] = arr[i - 1] + pda[i];
      if(arr[i] < N)
        ans += 1;
    }
    
    System.out.println(ans);
  }
}