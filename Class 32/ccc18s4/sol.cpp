#include <iostream>
using namespace std;

const int MN = 1e6+5;
int N;
long long dp[MN];

long long int dfs(int w){
	if(w == 1) return 1;
	if(dp[w] != -1) return dp[w];

	dp[w] = 0;
	for(int k = 2; k <= w; k++)
		dp[w] += dfs(w / k);
	return dp[w];
}

int main(){
	cin >> N;
	for(int i = 2; i <= N; i++) dp[i] = -1;
	cout << dfs(N);
}
