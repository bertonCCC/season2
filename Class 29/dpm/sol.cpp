#include <iostream>
using namespace std;

const int MN = 105, MK = 1e5+5, MOD = 1e9+7;
int N, K, limit[MN], dp[MN][MK], psa[MN][MK];

int main(){
	cin >> N >> K;
	for(int i = 1; i <= N; i++)
		cin >> limit[i];

	dp[0][0] = 1;

	for(int n = 1; n <= N; n++){
		psa[n - 1][0] = dp[n - 1][0];
		for(int k = 1; k <= K; k++)
			psa[n - 1][k] = (psa[n - 1][k - 1] + dp[n - 1][k]) % MOD;

		for(int k = 0; k <= K; k++){
			int lim = min(limit[n], k);
			// psa[n][k] = dp[n][0] + dp[n][1] + ... + dp[n][k];

			// we want dp[n - 1][k - lim] + ... + dp[n - 1][k]
			if(k - lim > 0)
				dp[n][k] = psa[n - 1][k] - psa[n - 1][k - lim - 1];
			else
				dp[n][k] = psa[n - 1][k];

			if(dp[n][k] < 0) dp[n][k] += MOD;
		}
	}

	cout << dp[N][K] << '\n';
}
