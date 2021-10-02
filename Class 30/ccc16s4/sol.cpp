#include <iostream>
using namespace std;

const int MN = 405;
int N, sizes[MN];
int dp[MN][MN]; // be -1, 0, or 1

int dfs(int l, int r){
	if(l >= r) return 1;
	if(dp[l][r] != -1) return dp[l][r];

	int sumA = 0, sumB = 0;
	for(int a = l, b = r + 1; a < b; a++){
		sumA += sizes[a];
		while(sumB < sumA && a + 1 < b){
			b -= 1;
			sumB += sizes[b];
		}

		if(a < b && sumA == sumB){
			if(dfs(l, a) == 1 && dfs(a + 1, b - 1) == 1 && dfs(b, r) == 1)
				return dp[l][r] = 1;
		}
	}

	return dp[l][r] = 0;
}

int main(){
	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> sizes[i];

	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			dp[i][j] = -1;

	int ans = 0;
	for(int l = 0; l < N; l++){
		for(int r = l; r < N; r++){
			if(dfs(l, r)){
				int total = 0;
				for(int i = l; i <= r; i++)
					total += sizes[i];
				ans = max(ans, total);
			}
		}
	}

	cout << ans << '\n';
}
