#include <iostream>
#include <iomanip>
using namespace std;

const int MN = 305;
int N, A, B, C;
double dp[MN][MN][MN];

double dfs(int a, int b, int c){
	if(a == 0 && b == 0 && c == 0) return 0;
	if(dp[a][b][c] != 0) return dp[a][b][c];

	double p = (a + b + c) / (double) N;

	int total = a + b + c;
	dp[a][b][c] = (1 - p) / p;
	if(a > 0) dp[a][b][c] += (a / (double) total) * (1 + dfs(a - 1, b, c));
	if(b > 0) dp[a][b][c] += (b / (double) total) * (1 + dfs(a + 1, b - 1, c));
	if(c > 0) dp[a][b][c] += (c / (double) total) * (1 + dfs(a, b + 1, c - 1));

	return dp[a][b][c];
}

int main(){
	cin >> N;
	for(int i = 0; i < N; i++){
		int n;
		cin >> n;
		if(n == 1) ++A;
		if(n == 2) ++B;
		if(n == 3) ++C;
	}

	cout << setprecision(12) << dfs(A, B, C) << '\n';
	// Java: System.out.printf("%.12f\n");
	// C: printf("%.12lf\n");
}
