#include <stdio.h>
#include <unordered_map>
using namespace std;

const int MAX = 1e5+5;
int N, K, arr[MAX];

/*
We need a data strucutre that

a) Add an element
b) Remove an element
c) Keep track of the number of distinct elements

We use a map from int -> int
Map Key = Array value
Map Value = Freq of that array value

When adding
a) The key already exists in the map - Add 1 to its value
b) The key doesn't exist yet - Init its value to 1

After removing
a) The new frequency is > 0 - Do nothing
b) The new frequency is 0 - Remove the key from the map

To get the number of distinct values = Size of the map (number of keys)
*/
int main(){
	scanf("%d %d", &N, &K);
	for(int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	int right = -1;
	long long ans = 0;
	unordered_map<int, int> freq;

	for(int left = 0; left < N; left++){
		while(right + 1 < N && freq.size() < K){
			if(freq.count(arr[right + 1]))
				freq[arr[right + 1]] += 1;
			else
				freq[arr[right + 1]] = 1;
			right++;
		}

		if(freq.size() >= K){
			ans += N - right;
		}

		freq[arr[left]] -= 1;
		if(freq[arr[left]] == 0)
			freq.erase(arr[left]);
	}

	printf("%I64d\n", ans);
}
