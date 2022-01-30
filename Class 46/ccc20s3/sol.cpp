#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

const int BASE = 131, MN = 2e5+5;
int freq[26], tarfreq[26];
#define pow power
#define hash hsh
#define unique unq
long long hash[MN], pow[MN];
unordered_set<int> unique;

long long substr(int left, int right){
	if(left == 0) return hash[right];
	return hash[right] - hash[left - 1] * pow[right - left + 1];
}

int main(){
	string needle, haystack;
	cin >> needle >> haystack;

	int N = needle.size(), M = haystack.size();

	hash[0] = haystack[0];
	pow[0] = 1;

	for(int i = 1; i < M; i++){
		hash[i] = hash[i - 1] * BASE + haystack[i];
		pow[i] = pow[i - 1] * BASE;
	}
	
	for(int i = 0; i < N; i++){
		int ascii = (int) needle[i];
		tarfreq[ascii - (int)'a'] += 1;
	}

	for(int i = 0; i < N; i++){
		int ascii = (int) haystack[i];
		freq[ascii - (int)'a'] += 1;
	}

	for(int i = 0; i < M - N + 1; i++){
		bool matching = true;
		for(int f = 0; f < 26; f++)
			if(freq[f] != tarfreq[f])
				matching = false;

		if(matching){
			unique.insert(substr(i, i + N - 1));
		}

		int ascii = (int) haystack[i];
		freq[ascii - (int)'a'] -= 1;

		if(i + N < M){
			ascii = (int) haystack[i + N];
			freq[ascii - (int)'a'] += 1;
		}
	}

	cout << unique.size() << '\n';
}
