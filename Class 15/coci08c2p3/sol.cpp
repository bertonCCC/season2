#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

int N;
int sour[10], bitter[10];

int main(){
	scanf("%d", &N);

	for(int i = 0; i < N; i++)
		scanf("%d %d", sour + i, bitter + i);

	int ans = 2 * 1000 * 1000 * 1000;

	for(int mask = 1; mask < (1 << N); mask++){
		int prod = 1, sum = 0;

		for(int pos = 0; pos < N; pos++){
			if((mask & (1 << pos)) > 0){
				prod *= sour[pos];
				sum += bitter[pos];
			}
		}

		ans = min(ans, abs(prod - sum));
	}

	printf("%d\n", ans);
}
