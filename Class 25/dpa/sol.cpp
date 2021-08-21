#include <iostream>
using namespace std;

const int MN = 1e5+5;
int N, ht[MN], dp[MN];

int dfs(int i){
	if(i == 1) return 0;
	if(i == 2) return abs(ht[1] - ht[2]);
	if(dp[i] != -1) return dp[i];
	return dp[i] = min(dfs(i - 1) + abs(ht[i - 1] - ht[i]),
	                   dfs(i - 2) + abs(ht[i - 2] - ht[i]));
}

int main(){
	cin >> N;
	for(int i = 1; i <= N; i++){
		cin >> ht[i];
		dp[i] = -1;
	}

	cout << dfs(N) << '\n';
}
