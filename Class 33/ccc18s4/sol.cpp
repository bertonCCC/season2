#include <iostream>
#include <unordered_map>
using namespace std;

const int MN = 1e6+5;
int N;
unordered_map<long long, long long> dp;

long long int dfs(int n){
	if(n <= 2) return 1;
	if(dp.count(n)) return dp[n];

	dp[n] = 0;
	int k = n;

	while(k >= 2){
		int v = n / k;
		int k0 = n / (v + 1);
		dp[n] += (k - k0) * dfs(v);
		k = k0;
	}

	return dp[n];
}

int main(){
	cin >> N;
	cout << dfs(N);
}
