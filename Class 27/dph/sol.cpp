#include <cstdio>
using namespace std;

const int MN = 1005, MOD = 1e9+7;
int R, C, dp[MN][MN];
char grid[MN][MN];

int main(){
	scanf("%d %d", &R, &C);

	for(int i = 1; i <= R; i++)
		for(int j = 1; j <= C; j++)
			scanf(" %c", &grid[i][j]);

	dp[1][1] = 1;
	for(int i = 1; i <= R; i++){
		for(int j = 1; j <= C; j++){
			if(grid[i][j] != '#' && !(i == 1 && j == 1))
				dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
		}
	}

	printf("%d\n", dp[R][C]);
}
