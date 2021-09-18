#include <iostream>
using namespace std;

const int MN = 2e5+5;
int N, height[MN], beauty[MN];
long long dp[MN], seg[MN * 4];

void update(int i, long long v, int l, int r, int p){
	if(l == r) seg[p] = v;
	else{
		int m = (l + r) / 2;
		if(i <= m) update(i, v, l, m, p * 2);
		else update(i, v, m + 1, r, p * 2 + 1);

		seg[p] = max(seg[p * 2], seg[p * 2 + 1]);
	}
}

long long query(int ql, int qr, int l, int r, int p){
	if(l > qr || r < ql) return -1;
	if(l >= ql && r <= qr) return seg[p];
	int m = (l + r) / 2;
	return max(
		query(ql, qr, l, m, p * 2),
		query(ql, qr, m + 1, r, p * 2 + 1)
	);
}

int main(){
	cin >> N;
	for(int i = 1; i <= N; i++)
		cin >> height[i];
	for(int i = 1; i <= N; i++)
		cin >> beauty[i];

	for(int n = 1; n <= N; n++){
		// use the data structure
		long long best = query(0, height[n] - 1, 0, N, 1);

		// calculate dp[n]
		dp[n] = best + beauty[n];

		// update the data structure
		update(height[n], dp[n], 0, N, 1);
	}

	long long ans = 0;
	for(int i = 1; i <= N; i++)
		ans = max(ans, dp[i]);
	cout << ans << '\n';
}
