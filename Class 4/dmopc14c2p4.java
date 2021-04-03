import java.util.*;

public class dmopc14c2p4{
  public static void main(String[] args){
    Scanner in = new Scanner(System.in);
    
    int N = in.nextInt();
    int[] arr = new int[N];
    int[] psa = new int[N];
    
    for(int i = 0; i < N; i++){
      arr[i] = in.nextInt();
    }
    
    psa[0] = arr[0];
    for(int i = 1; i < N; i++)
      psa[i] = psa[i - 1] + arr[i];
    
    int Q = in.nextInt();
    
    for(int i = 0; i < Q; i++){
      int a = in.nextInt(), b = in.nextInt();
      if(a == 0)
        System.out.println(psa[b]);
      else
        System.out.println(psa[b] - psa[a - 1]);
    }
  }
}