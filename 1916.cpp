#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> P;

const int MAX_cost = 10000;
const int MAX_city = 1000;

int main ()
{
	int N, M;
	vector<P> dis[MAX_cost];
	
	cin >> N;
	cin >> M;
	
	for(int i = 0; i < M; i++)
	{
		int st, en, co;
		cin >> st >> en >> co;
		dis[st].push_back(P(en, co));
	}
	
	int start, end;
	
	cin >> start >> end;
	
	int dist[MAX_city];
	bool visited[MAX_city] = {0};
	fill(dist, dist+MAX_city, MAX_cost);
	priority_queue<P, vector<P>, greater<P>> PQ;
	
	dist[start] = 0;
	PQ.push(P{0, start});
	while(!PQ.empty())
	{
		int cur;
		do
		{
			cur = PQ.top().second;
			PQ.pop();
		}while(!PQ.empty() && visited[cur]);
		
		if(visited[cur])
		break;
		
		visited[cur] = true;
		for(auto &p: dis[cur])
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
	
	cout << dist[end];
}
