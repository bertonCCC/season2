#include <iostream>
#include <iomanip>
using namespace std;

const int MN = 3005;
int N;
double prob[MN];
double dp[MN][MN];

int main(){
	cin >> N;
	for(int i = 1; i <= N; i++)
		cin >> prob[i];

	dp[0][0] = 1;
	for(int n = 1; n <= N; n++){
		dp[n][0] = (1 - prob[n]) * dp[n - 1][0];
		for(int h = 1; h <= n; h++){
			dp[n][h] = prob[n] * dp[n - 1][h - 1] + (1 - prob[n]) * dp[n - 1][h];
		}
	}

	double ans = 0.0;
	for(int i = N / 2 + 1; i <= N; i++)
		ans += dp[N][i];
	cout << setprecision(12) << ans << '\n';
	// <cstdio>: printf("%.12lf\n", ans);
	// Java: System.out.printf("%.12f\n", ans);
}
