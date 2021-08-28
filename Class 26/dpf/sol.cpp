#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int MN = 3005;
string str, ttr;
int N, M, dp[MN][MN], trace[MN][MN];

int main(){
	cin >> str >> ttr;

	N = str.size();
	M = ttr.size();

	str = string("$") + str;
	ttr = string("$") + ttr;
		
	const int diag = 0, left = 1, above = 2;

	for(int n = 1; n <= N; n++){
		for(int m = 1; m <= M; m++){
			if(str[n] == ttr[m]){
				dp[n][m] = 1 + dp[n - 1][m - 1];
				trace[n][m] = diag;
			}
			else if(dp[n - 1][m] > dp[n][m - 1]){
				dp[n][m] = dp[n - 1][m];
				trace[n][m] = above;
			}
			else{
				dp[n][m] = dp[n][m - 1];
				trace[n][m] = left;
			}
		}
	}

	string ans = "";

	int curN = N, curM = M;
	while(curN != 0 && curM != 0){
		if(trace[curN][curM] == diag){ // str[curN] == ttr[curM]
			ans += str[curN];
			curN -= 1;
			curM -= 1;
		}
		else if(trace[curN][curM] == left){
			curM -= 1;
		}
		else{
			curN -= 1;
		}
	}

	reverse(ans.begin(), ans.end());
	cout << ans << '\n';
}
