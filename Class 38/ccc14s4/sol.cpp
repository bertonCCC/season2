#include <iostream>
#include <algorithm>
#include <map>
#include <tuple>
#include <vector>
using namespace std;

struct event{
	int x, y1, y2, tint;
	bool left;
};
int N, T;

int main(){
	cin >> N >> T;
	vector<event> events;
	for(int i = 0; i < N; i++){
		int x1, y1, x2, y2, tint;
		cin >> x1 >> y1 >> x2 >> y2 >> tint;

		events.push_back(event { x1, y1, y2, tint, true  });
		events.push_back(event { x2, y1, y2, tint, false });
	}

	sort(events.begin(), events.end(), [] (event a, event b){
		return a.x < b.x;
	});

	// y-coord, difference in tint factor
	map<int, int> subevents;
	long long ans = 0;

	int E = events.size();
	for(int i = 0; i < E; i++){
		long long tint_factor = 0;
		int height = 0;

		int prev_yvalue = -1;

		for(auto [yvalue, tint] : subevents){
			if(prev_yvalue != -1){
				if(tint_factor >= T)
					height += yvalue - prev_yvalue;
			}

			tint_factor += tint;
			prev_yvalue = yvalue;
		}

		if(i > 0)
			ans += 1LL * height * (events[i].x - events[i - 1].x);

		int y1 = events[i].y1, y2 = events[i].y2, tint = events[i].tint;

		if(events[i].left){
			if(subevents.count(y1))
				subevents[y1] += tint;
			else
				subevents[y1] = tint;

			if(subevents.count(y2))
				subevents[y2] -= tint;
			else
				subevents[y2] = -tint;
		}
		else{
			subevents[y1] -= tint;
			if(subevents[y1] == 0)
				subevents.erase(y1);

			subevents[y2] += tint;
			if(subevents[y2] == 0)
				subevents.erase(y2);
		}
	}

	cout << ans << '\n';
}
