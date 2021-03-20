#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;

    unordered_set<string> hs, ans;

    for(int i = 0; i < N; i++){
        string s;
        cin >> s;

        hs.insert(s);
    }

    for(int i = 0; i < M; i++){
        string s;
        cin >> s;

        if(hs.count(s))
            ans.insert(s);
    }

    cout << ans.size();
}
