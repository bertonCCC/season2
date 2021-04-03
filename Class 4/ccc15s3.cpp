#include <stdio.h>
#include <set>
using namespace std;

int main(){
    int G, P;
    scanf("%d %d", &G, &P);

    set<int> open;

    for(int i = 1; i <= G; i++)
        open.insert(-i);

    int ans = 0;
    for(int i = 0; i < P; i++){
        int g;
        scanf("%d", &g);

        auto result = open.lower_bound(-g);
        // this gives us the location of the smallest number >= -g
        // if this location is equal to open.end(), then no such number exists
        // otherwise we can use the * operator to find the actual value

        if(result == open.end())
            break;
        else{
            ans += 1;
            int gate = *result;
            open.erase(gate);
        }
    }

    printf("%d\n", ans);
}
