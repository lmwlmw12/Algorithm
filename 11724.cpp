#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1001;

vector<int> line[MAX]; // 인접 
bool visited[MAX]; // 방문 여부 

int DFS(int node)
{
	visited[node] = true;
	
	for(int i = 0; i < line[node].size(); i++)
	{
		int next = line[node][i];
		if(visited[next] == false)
		{
			DFS(next);
		}
	} 
}

int main()
{
	int N, M;
	int u, v;
	int cnt;
	
	cin >> N >> M;
	
	for(int i = 0; i < M; i++)
	{
		cin >> u >> v;
		line[u].push_back(v);
		line[v].push_back(u); 
	}
	
	for(int j = 1; j <= N; j++)
	{
		if(visited[j] == false)
		{
			DFS(j);
			cnt++;
		}
		
	}
	
	cout << cnt;
}
