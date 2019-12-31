#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lct[26][26];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

vector<int> v;

bool visited[26][26];
int count_ = 1;

int DFS(int x, int y, int n)
{

	visited[x][y] = true;
	
	for(int i = 0; i < 4; i++)
	{
		int ax = x + dx[i];
		int ay = y + dy[i];
		
		if(ax < 0 || ay < 0 || ax >= n || ay >= n || visited[ax][ay] == true)
		continue;
		
		if(lct[ax][ay] == 1 && visited[ax][ay] == false)
		{
			count_++;
			DFS(ax, ay, n);
		}
	}
	
}

int main()
{
	int N;
	int cnt;
	
	cin >> N;
	
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			scanf("%1d", &lct[i][j]);
		}
	}
	
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if(lct[i][j] == 1 && visited[i][j] == false)
			{
				count_ = 1;
				DFS(i, j, N);
				cnt++;
				v.push_back(count_);
			}
		}
	}
	
	sort(v.begin(), v.end());
	
	cout << cnt << endl;
	
	for(int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}
	
	
}
