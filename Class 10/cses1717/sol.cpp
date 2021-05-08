#include <stdio.h>

typedef long long int lli;
const int MN = 1e6+5, MOD = 1e9+7;
int N;
lli fac[MN];

lli pow(lli base, lli exp){
	if(exp == 0) return 1;
	if(exp % 2 == 1) return base * pow(base * base % MOD, exp / 2) % MOD;
	else return pow(base * base % MOD, exp / 2);
}

lli choose(int n, int k){
	// n!/(n-k)!k!
	return fac[n] * pow(fac[k], MOD - 2) % MOD
		* pow(fac[n - k], MOD - 2) % MOD;
}

int main(){
	scanf("%d", &N);
	fac[0] = 1;
	for(int i = 1; i <= N; i++)
		fac[i] = fac[i - 1] * i % MOD;

	lli sum = 0;
	for(int i = 1; i <= N; i++){
		lli part = fac[N - i] * choose(N, i) % MOD;
		if(i % 2 == 1) sum = (sum + part) % MOD;
		else sum = (sum - part + MOD) % MOD;
	}

	lli ans = (fac[N] - sum + MOD) % MOD;
	printf("%lld\n", ans);
}
