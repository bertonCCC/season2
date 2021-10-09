#include <iostream>
using namespace std;

int N, dp[31][31][31][31];

int dfs(int a, int b, int c, int d){
	if(a < 0 || b < 0 || c < 0 || d < 0) return -2;
	if(dp[a][b][c][d] != -1) return dp[a][b][c][d];

	if(dfs(a - 2, b - 1, c, d - 2) == 0) return dp[a][b][c][d] = 1;
	if(dfs(a - 1, b - 1, c - 1, d - 1) == 0) return dp[a][b][c][d] = 1;
	if(dfs(a, b, c - 2, d - 1) == 0) return dp[a][b][c][d] = 1;
	if(dfs(a, b - 3, c, d) == 0) return dp[a][b][c][d] = 1;
	if(dfs(a - 1, b, c, d - 1) == 0) return dp[a][b][c][d] = 1;

	return dp[a][b][c][d] = 0;
}

int main(){
	cin >> N;
	for(int a = 0; a <= 30; a++)
		for(int b = 0; b <= 30; b++)
			for(int c = 0; c <= 30; c++)
				for(int d = 0; d <= 30; d++)
					dp[a][b][c][d] = -1;

	for(int i = 0; i < N; i++){
		int A, B, C, D;
		cin >> A >> B >> C >> D;
		if(dfs(A, B, C, D) == 1)
			cout << "Patrick\n";
		else
			cout << "Roland\n";
	}
}
