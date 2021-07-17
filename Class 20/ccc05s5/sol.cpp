#include <algorithm>
#include <stdio.h>
using namespace std;

const int MN = 1e5+5;
int N, score[MN], sorted[MN], fen[MN];

void add(int n, int v){
	for(int i = n; i < MN; i += i & -i)
		fen[i] += v;
}

int query(int n){
	int sum = 0;
	for(int i = n; i > 0; i -= i & -i)
		sum += fen[i];
	return sum;
}

int main(){
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
		scanf("%d", &score[i]);

	for(int i = 0; i < N; i++)
		sorted[i] = score[i];

	sort(sorted, sorted + N);

	for(int i = 0; i < N; i++)
		score[i] = lower_bound(sorted, sorted + N, score[i]) - sorted + 1;

	long long total = 0;
	for(int i = 0; i < N; i++){
		int rank = i - query(score[i]) + 1;
		total += rank;

		add(score[i], 1);
	}

	printf("%.2lf\n", (double) total/N);
}
