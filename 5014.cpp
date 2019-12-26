#include <iostream>
#include <queue>

using namespace std;

bool visited[1000001];

int BFS(int f, int s, int g, int u, int d)
{
	queue<pair<int, int> > q;
	int count = 0;
	
	q.push({s, count});
	visited[s] = true;
	
	while(!q.empty())
	{
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();
		
		if(cur == g)
		{
			return cnt;
		}
		
		// U
		if(cur + u <= f && visited[cur+u] == false)
		{
			int res = cur + u;
			visited[res] = true;
			q.push({res, cnt+1});
		}
		
		// D
		if(cur - d > 0 && visited[cur-d] == false)
		{
			int res = cur - d;
			visited[res] = true;
			q.push({res, cnt+1});
		}		
	}
	
	return -1;
}

int main ()
{
	int F, S, G, U, D;
	
	cin >> F >> S >> G >> U >> D;
	
	int result = BFS(F, S, G, U, D);
	
	if(result == -1)
	{
		cout << "use the stairs";
	}
	else
	cout << result;
}
