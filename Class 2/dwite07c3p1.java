import java.util.*;

public class dwite07c3p1{
  public static void main(String[] args){
    Scanner in = new Scanner(System.in);
    for(int j = 0; j < 5; j++){
      int n = in.nextInt();
      int count = 0; // number of factors
      
      for(int i = 2; i * i <= n; i++){
        if(n % i == 0){
          count += 1;
          // ++count, count++
          
          while(n % i == 0)
            n /= i;
        }
      }
      
      if(n > 1) count += 1;
      
      if(count == 3) System.out.println("valid");
      else System.out.println("not");
    }
  }
}