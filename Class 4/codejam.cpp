#include <stdio.h>
#include <string.h>
using namespace std;

const int MN = 1005;
int T, N, X, Y;
char str[MN];

int calc(int i, int j){
	if(i > j) return 0;
	if(i == 0 || j == N - 1) return 0;
	if(str[i - 1] == str[j + 1]) return 0;
	if(str[i - 1] == 'C' && str[j + 1] == 'J') return X;
	if(str[i - 1] == 'J' && str[j + 1] == 'C') return Y;
	return -1000000;
}

void solve(int CNUM){
	scanf("%d %d %s", &X, &Y, str);
	N = strlen(str);

	int ans = 0;
	for(int i = 0; i < N - 1; i++){
		if(str[i] == 'C' && str[i + 1] == 'J') ans += X;
		if(str[i] == 'J' && str[i + 1] == 'C') ans += Y;
	}

	int len = 0;
	for(int i = 0; i < N; i++){
		if(str[i] == '?') ++len;
		else{
			ans += calc(i - len, i - 1);
			len = 0;
		}
	}
	ans += calc(N - len, N - 1);
	printf("Case #%d: %d\n", CNUM, ans);
}

int main(){
	scanf("%d", &T);
	for(int i = 1; i <= T; i++){
		solve(i);
	}
}
