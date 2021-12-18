#include <iostream>
#include <tuple>
using namespace std;

const int MN = 1e4+5;
int N, arr[MN], dp[MN];

int group2(int a, int b){
	return a + b - min(a, b) / 2;
}

int group3(int a, int b, int c){
	return a + b + c - min(min(a, b), c);
}

int main(){
	cin >> N;
	for(int i = 1; i <= N; i++){
		cin >> arr[i];
		arr[i] *= 2; // multiply all prices by 2, divide by 2 at the end
	}

	// dp[i] is the minimum price with grouping for the first i elements
	for(int i = 1; i <= N; i++){
		// no grouping case
		dp[i] = dp[i - 1] + arr[i];

		// try grouping arr[i - 1] and arr[i]
		if(i >= 2) dp[i] = min(dp[i], dp[i - 2] + group2(arr[i - 1], arr[i]));

		// try grouping arr[i - 2], arr[i - 1], arr[i]
		if(i >= 3) dp[i] = min(dp[i], dp[i - 3] + group3(arr[i - 2], arr[i - 1], arr[i]);
	}

	// answer is now dp[N] / 2

	cout << dp[N] / 2;

	if(dp[N] % 2 == 1) // dp[N] is odd, so will have .5
		cout << ".5";
	else // is even, so will have .0
		cout << ".0";
}
