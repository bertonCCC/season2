#include <stdio.h>
#include <string.h>

const int MN = 1e6+5, BASE = 123456;
char str[MN], pat[MN];
#define pow pow_something_else
long long int pha[MN], pow[MN];

long long int substr(int l, int r){
	if(l == 0)
		return pha[r];
	else
		return pha[r] - pha[l - 1] * pow[r - l + 1];
}

int main(){
	scanf("%s %s", str, pat);
	int N = strlen(str), M = strlen(pat);

	pha[0] = str[0];
	pow[0] = 1;
	for(int i = 1; i < N; i++){
		pha[i] = (pha[i - 1] * BASE + str[i]);
		pow[i] = pow[i - 1] * BASE;
	}

	long long int pathash = pat[0];
	for(int i = 1; i < M; i++){
		pathash = (pathash * BASE + pat[i]);
	}

	for(int i = 0; i < N - M + 1; i++){
		int l = i, r = i + M - 1;
		long long int subhash = substr(l, r);
		if(subhash == pathash){
			printf("%d\n", i);
			return 0;
		}
	}

	printf("-1\n");
}
