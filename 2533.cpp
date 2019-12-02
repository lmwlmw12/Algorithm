#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

const int MAX_SIZE = 1000000;

int N;
vector<int> friend_[MAX_SIZE];
vector<int> dirNode[MAX_SIZE];
bool visited[MAX_SIZE];
int dp[MAX_SIZE][2];

void DFS(int cur)
{
    visited[cur] = true;
    for(int i = 0; i < friend_[cur].size(); i++)
    {
    	int next = friend_[cur][i];
    	
    	if(!visited[next])
    	{
    		dirNode[cur].push_back(next);
    		DFS(next);
		}
	}
}

int early_adapter(int cur, bool early) 
{
	int &result = dp[cur][early];
	if(result != -1)
	{
		return result;
	}
	
	if(early)
	{
		result = 1;
		for(int i = 0; i < dirNode[cur].size(); i++)
		{
			int next = dirNode[cur][i];
			result += min(early_adapter(next, true), early_adapter(next, false));
		}
	}
	else
	{
		result = 0;
		for(int j = 0; j < dirNode[cur].size(); j++)
		{
			int next = dirNode[cur][j];
			result += early_adapter(next, true);
		}
	}
	return result;
}

int main() 
{
	
	int u, v; 
	
	cin >> N;
		
	for(int i = 0; i < N-1; i++) {
		
		cin >> u >> v;
		friend_[u].push_back(v);
		friend_[v].push_back(u);
		
	}
	
	memset(dp, -1, sizeof(dp));
	
	DFS(1);	
	
	cout << min(early_adapter(1, false), early_adapter(1, true)) << endl;
	
	return 0;
}
