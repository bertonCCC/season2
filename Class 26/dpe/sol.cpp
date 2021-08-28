#include <iostream>
using namespace std;

const int MN = 105, MV = 1e5+5;
const long long INF = 1e12;
int N, W, wt[MN], val[MN];
long long dp[MN][MV];

int main(){
	cin >> N >> W;
	for(int i = 1; i <= N; i++)
		cin >> wt[i] >> val[i];

	for(int i = 0; i <= N; i++)
		for(int v = 1; v < MV; v++)
			dp[i][v] = INF;

	for(int i = 1; i <= N; i++){
		for(int v = 0; v < MV; v++){
			if(val[i] <= v) dp[i][v] = min(wt[i] + dp[i - 1][v - val[i]], dp[i - 1][v]);
			else dp[i][v] = dp[i - 1][v];
		}
	}

	for(int v = MV - 1; v >= 0; v--){
		if(dp[N][v] <= W){
			cout << v;
			break;
		}
	}
}
