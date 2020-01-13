#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> P;

const int MAX_dot = 801;

vector<P> dir[MAX_dot];

vector<int> dijkstra(int num, int res)
{
	vector<int> dist(res, 987654321);
	dist[num] = 0;
	
	priority_queue<P, vector<P>, greater<P>> PQ;
	
	PQ.push(P(0, num));
	
	while(!PQ.empty())
	{

		int cost = PQ.top().first;
		int cur = PQ.top().second;

		PQ.pop();
		
		if(dist[cur] < cost)
		continue;
		
		for(auto &p: dir[cur])
		{
			int next = p.first;
			int d = p.second;
			
			if(dist[next] > dist[cur] + d)
			{
				dist[next] = dist[cur] + d;
				PQ.push(P(dist[next], next));
			}
		}
	}
	return dist;
} 

int main ()
{
	int N, E;
	
	cin >> N >> E;
	
	N++;
	
	for(int i = 0; i < E; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		dir[a].push_back(P(b,c));
		dir[b].push_back(P(a,c));
	}
	
	int must_one, must_two;
	cin >> must_one >> must_two;
	
	vector<int> result = dijkstra(1, N);
	vector<int> node1 = dijkstra(must_one, N);
	vector<int> node2 = dijkstra(must_two, N);
	
	int ans = min({result[must_one] + node1[must_two] + node2[N-1], result[must_two] + node2[must_one] + node1[N-1]});
	
	if(ans >= 987654321 || ans <0)
	{
		cout << -1;
	}
	else
	cout << ans;
}
