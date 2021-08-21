#include <iostream>
using namespace std;

const int MN = 1e5+5;
int N, a[MN], b[MN], c[MN], dpa[MN], dpb[MN], dpc[MN];

int main(){
	cin >> N;
	for(int i = 1; i <= N; i++)
		cin >> a[i] >> b[i] >> c[i];

	for(int i = 1; i <= N; i++){
		dpa[i] = a[i] + max(dpb[i - 1], dpc[i - 1]);
		dpb[i] = b[i] + max(dpa[i - 1], dpc[i - 1]);
		dpc[i] = c[i] + max(dpa[i - 1], dpb[i - 1]);
	}

	int ans = max(dpa[N], max(dpb[N], dpc[N]));
	cout << ans << '\n';
}
