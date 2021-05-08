#include <stdio.h>

const int MOD = 1e9+7, MOD2 = 1e9+6;
typedef long long lli;

// base ^ exp % mod
lli pow(lli base, lli exp){
	if(exp == 0) return 1;
	if(exp % 2 == 1) // exp is odd
		return base * pow(base * base % MOD, exp / 2) % MOD;
	else
		return pow(base * base % MOD, exp / 2);
}

lli pow2(lli base, lli exp){
	if(exp == 0) return 1;
	if(exp % 2 == 1) // exp is odd
		return base * pow(base * base % MOD2, exp / 2) % MOD2;
	else
		return pow(base * base % MOD2, exp / 2);
}

int main(){
	int K, M, B = 0;
	scanf("%d %d", &K, &M);

	int power = 1; // or just do 1 << K
	for(int i = 0; i < K; i++)
		power *= 2;

	for(int i = 0; i < power; i++){
		for(int j = 0; j < power; j++){
			char ch;
			scanf(" %c", &ch);
			if(ch == '#')
				B += 1;
		}
	}

	// (2^(4^M) - 1)^ B

	lli part1 = pow2(4, M);
	lli part2 = (pow(2, part1) - 1 + MOD) % MOD;
	lli part3 = pow(part2, B);

	printf("%lld\n", part3);
}
