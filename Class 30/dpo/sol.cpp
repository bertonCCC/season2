#include <iostream>
using namespace std;

const int MOD = 1e9+7;
int N, compat[22][22];
int dp[(1 << 21) + 5];

// number of ways to match first n men with the set of women represented by the mask
// where n = # of on-bits of the mask (the size of set of women)
int dfs(int mask){
	if(mask == 0) return 1;
	if(dp[mask] != -1) return dp[mask];

	int n = 0;
	for(int i = 0; i < N; i++)
		if((mask & (1 << i)) != 0)
			n += 1;

	n -= 1; // to account for 0-indexing

	dp[mask] = 0;

	for(int w = 0; w < N; w++)
		if(compat[n][w] && (mask & (1 << w)))
			dp[mask] = (dp[mask] + dfs(mask ^ (1 << w))) % MOD;

	return dp[mask];
}

int main(){
	cin >> N;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			cin >> compat[i][j];

	for(int i = 0; i < (1 << N); i++)
		dp[i] = -1;

	cout << dfs((1 << N) - 1);
}
