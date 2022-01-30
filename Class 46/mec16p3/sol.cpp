#include <iostream>
using namespace std;

const int MN = 105;
int N, T, levels[MN];
#define time tm
int time[MN][MN], xp[MN][MN], dp[MN][MN];

int main(){
	cin >> N >> T;
	for(int i = 1; i <= N; i++){
		cin >> levels[i];
		for(int j = 0; j < levels[i]; j++){
			cin >> time[i][j] >> xp[i][j];
		}
	}

	for(int s = 1; s <= N; s++){
		for(int t = 0; t <= T; t++){
			dp[s][t] = dp[s - 1][t];

			int sumTime = 0, sumXp = 0;
			for(int l = 0; l < levels[s]; l++){
				// considering the first l levels of the s-th skill
				sumTime += time[s][l];
				sumXp += xp[s][l];

				if(sumTime <= t)
					dp[s][t] = max(dp[s][t], dp[s - 1][t - sumTime] + sumXp);
			}
		}
	}

	cout << dp[N][T] << '\n';
}
