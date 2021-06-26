#include <stdio.h>
#include <queue>
#include <tuple>
using namespace std;

bool vist[9][9];
int dist[9][9];

int main(){
	int SR, SC, TR, TC;
	scanf("%d %d %d %d", &SR, &SC, &TR, &TC);

	queue<pair<int, int>> que;
	que.push({SR, SC});
	vist[SR][SC] = true;

	int dr[8] = {-2, -2, -1, 1, -1, 1, 2, 2};
	int dc[8] = {-1, 1, -2, -2, 2, 2, -1, 1};

	while(!que.empty()){
		int r, c;
		pair<int, int> cur = que.front();
		que.pop();
		tie(r, c) = cur; // unpack the pair into r and c

		if(r == TR && c == TC){
			printf("%d\n", dist[r][c]);
			return 0;
		}

		for(int i = 0; i < 8; i++){
			int nr = r + dr[i], nc = c + dc[i];
			if(nr >= 1 && nr <= 8 && nc >= 1 && nc <= 8 && !vist[nr][nc]){
				vist[nr][nc] = true;
				que.push({nr, nc});
				dist[nr][nc] = dist[r][c] + 1;
			}
		}
	}
}
