#include <string>
#include <iostream>
using namespace std;

string str;
const int MN = 2e6+5;
int N, M, pre[MN];

int main(){
	string s, t;
	cin >> s >> t;
	N = s.size();
	M = t.size();

	str = t + "#" + s;

	int n = str.size();
	for(int i = 1; i < n; i++){
		int best = pre[i - 1];
		while(best > 0 && str[i] != str[best])
			best = pre[best - 1];
		if(str[i] == str[best])
			best += 1;
		pre[i] = best;
	}

	for(int i = M + 1; i < n; i++){
		if(pre[i] == M){
			cout << i - (M - 1) - (M + 1) << endl;
			return 0;
		}
	}

	cout << -1 << endl;
}
