#include <cstdio>
#include <unordered_map>
#include <set>
#include <tuple>
using namespace std;

int main(){
    int N, Q;
    scanf("%d %d", &N, &Q);

    set<pair<int, int>> hs;
    unordered_map<int, int> xmap, ymap;

    for(int i = 0; i < N; i++){
        int x, y;
        scanf("%d %d", &x, &y);

        hs.insert({x, y});

        xmap[x] += 1;
        ymap[y] += 1;
    }

    for(int i = 0; i < Q; i++){
        int type;
        scanf("%d", &type);

        if(type == 1){
            int x, y;
            scanf("%d %d", &x, &y);

            if(hs.count({x, y}))
                printf("salty\n");
            else
                printf("bland\n");
        }
        else{
            char subtype;
            scanf(" %c", &subtype);

            if(subtype == 'X'){
                int x;
                scanf("%d", &x);
                if(xmap.count(x))
                    printf("%d\n", xmap[x]);
                else
                    printf("0\n");
            }
            else{
                int y;
                scanf("%d", &y);
                if(ymap.count(y))
                    printf("%d\n", ymap[y]);
                else
                    printf("0\n");
            }
        }
    }
}
