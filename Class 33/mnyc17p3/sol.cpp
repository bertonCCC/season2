#include <stdio.h>
#include <string.h>
#include <tuple>
using namespace std;

const int MN = 1e6+5, BASE1 = 234567, MOD1 = 1e9+7, BASE2 = 123456, MOD2 = 1e9+9;
char astr[MN], bstr[MN];
int N, M;
long long ahash1[MN], bhash1[MN], ahash2[MN], bhash2[MN], power1[MN], power2[MN];

int main(){
	scanf("%s %s", astr, bstr);
	N = strlen(astr);
	M = strlen(bstr);

	power1[0] = power2[0] = 1;
	for(int i = 1; i < N; i++){
		power1[i] = power1[i - 1] * BASE1 % MOD1;
		power2[i] = power2[i - 1] * BASE2 % MOD2;
	}

	for(int i = N - 1, p = 0; i >= 0; i--, p++){
		ahash1[i] = (astr[i] * power1[p] + ahash1[i + 1]) % MOD1;
		ahash2[i] = (astr[i] * power2[p] + ahash2[i + 1]) % MOD2;
	}

	bhash1[0] = bhash2[0] = bstr[0];
	for(int i = 1; i < M; i++){
		bhash1[i] = (bhash1[i - 1] * BASE1 + bstr[i]) % MOD1;
		bhash2[i] = (bhash2[i - 1] * BASE2 + bstr[i]) % MOD2;
	}

	int best = 0;
	for(int len = 1; len <= min(N, M); len++){
		if(ahash1[N - len] == bhash1[len - 1] && ahash2[N - len] == bhash2[len - 1])
			best = max(best, len);
	}

	//printf("%s%s", astr, bstr + best);
	printf("%s", astr);
	for(int i = best; i < M; i++)
		printf("%c", bstr[i]);
}
