#include <iostream>
using namespace std;

const int MN = 105, MW = 1e5+5;
int N, W, wt[MN], val[MN];
long long dpOld[MW], dpNew[MW];

int main(){
	cin >> N >> W;
	for(int i = 1; i <= N; i++)
		cin >> wt[i] >> val[i];

	for(int i = 1; i <= N; i++){
		for(int w = 0; w <= W; w++){
			if(w >= wt[i])
				dpNew[w] = max(val[i] + dpOld[w - wt[i]], dpOld[w]);
			else
				dpNew[w] = dpOld[w];
		}

		for(int w = 0; w <= W; w++)
			dpOld[w] = dpNew[w];
	}

	cout << dpNew[W] << endl;
}
