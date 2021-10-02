import java.util.*;

public class sol{
	static int N;
	static final int MOD = 1000 * 1000 * 1000 + 7;
	static boolean[][] compat = new boolean[21][21];
	static int[] dp = new int[2097152];
	// dp[mask] is the number of ways the mask corresponding to a subset of women
	// can be paired up to the first k men where k is the number of bits
	// on in the mask

	// dp[mask] = for all on-bits:
	// dp[mask without that bit] if the woman corresponding to that bit is
	// compatible with the k-th man

	// answer is dp[all women]
	
	// base case: dp[0] = 1

	static int dfs(int mask){
		if(mask == 0) return 1;
		if(dp[mask] != -1) return dp[mask];

		int k = 0;
		for(int bit = 0; bit < N; bit++){
			if((mask & (1 << bit)) != 0)
				++k;
		}

		dp[mask] = 0;

		// ** women are 0-indexed while k is 1-indexed
		for(int bit = 0; bit < N; bit++){
			// woman corresponding to bit is included in the subset
			if((mask & (1 << bit)) != 0 && compat[bit][k - 1]){
				dp[mask] = (dp[mask] + dfs(mask ^ (1 << bit))) % MOD;
			}
		}

		return dp[mask];
	}

	public static void main(String[] args){
		for(int i = 0; i < 2097152; i++)
			dp[i] = -1;

		Scanner in = new Scanner(System.in);
		
		N = in.nextInt();
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				int n = in.nextInt();
				if(n == 1) compat[i][j] = true;
				else compat[i][j] = false;
			}
		}

		int ans = dfs((1 << N) - 1);
		System.out.println(ans);
	}
}