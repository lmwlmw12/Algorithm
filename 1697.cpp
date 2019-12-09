#include <iostream>
#include <queue>

using namespace std;

const int MAX = 100000;

int N, K;
bool visited[MAX];
queue<pair<int, int> > q;

int BFS() {
	
	q.push({N, 0});
	visited[N] = true;
	
	while(!q.empty())
	{
		int cur = q.front().first;
		int time = q.front().second;
		q.pop();
		
		if(cur == K)
		{
			return time;
		}
		
		int walk_fwrd = cur + 1;
		
		if(walk_fwrd <= MAX && !visited[walk_fwrd])
		{
			visited[walk_fwrd] = true;
			q.push({walk_fwrd, time+1});
		}
		
		int walk_bwrd = cur -1;
		
		if(walk_bwrd >= 0 && !visited[walk_bwrd])
		{
			visited[walk_bwrd] = true;
			q.push({walk_bwrd, time+1});
		}
		
		
		int teleport = cur * 2;
		
		if(teleport <= MAX && !visited[teleport])
		{
			visited[teleport] = true;
			q.push({teleport, time+1});
		}
		
		time++;
		
	}
}

int main () {
	
	cin >> N >> K;
	
	cout << BFS();
}
