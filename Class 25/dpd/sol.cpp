// this code doesn't work yet, it uses too much space

#include <iostream>
using namespace std;

const int MN = 105, MW = 1e5+5;
int N, W, wt[MN], val[MN];
long long dp[MN][MW];

int main(){
	cin >> N >> W;
	for(int i = 1; i <= N; i++)
		cin >> wt[i] >> val[i];

	for(int i = 1; i <= N; i++){
		for(int w = 0; w <= W; w++){
			if(w >= wt[i])
				dp[i][w] = max(val[i] + dp[i - 1][w - wt[i]], dp[i - 1][w]);
			else
				dp[i][w] = dp[i - 1][w];
		}
	}

	cout << dp[N][W] << endl;
}
