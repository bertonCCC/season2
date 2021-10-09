#include <iostream>
using namespace std;

const int MN = 37, MD = 6000, INF = 1e9;
int D, N, sizes[MN];
int dp[MD];

int main(){
	cin >> D >> N;
	for(int i = 0; i < N; i++)
		cin >> sizes[i];

	for(int i = 1; i <= D; i++)
		dp[i] = INF;
	dp[0] = 0;

	for(int n = 0; n < N; n++){
		for(int d = 1; d <= D; d++){
			if(d >= sizes[n])
				dp[d] = min(dp[d], dp[d - sizes[n]] + 1);
		}
	}

	if(dp[D] == INF)
		cout << "Roberta acknowledges defeat.\n";
	else
		cout << "Roberta wins in " << dp[D] << " strokes.\n";
		// printf("Roberta wins in %d strokes.\n", dp[D]);
}
