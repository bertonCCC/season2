#include <iostream>
using namespace std;

const int MN = 1e5+5;
const int INF = 2e9;
int N, K, ht[MN], dp[MN];

int main(){
	cin >> N >> K;
	for(int i = 1; i <= N; i++)
		cin >> ht[i];

	dp[1] = 0;

	for(int i = 2; i <= N; i++){
		dp[i] = INF;
		// k is the number of stones jumping forwards to current
		// stone i
		for(int k = 1; k <= K; k++){
			if(i - k >= 1)
				dp[i] = min(dp[i], dp[i - k] + abs(ht[i - k] - ht[i]));
		}
	}

	cout << dp[N] << '\n';
}
