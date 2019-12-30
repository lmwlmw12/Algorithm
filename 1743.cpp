#include <iostream>
#include <vector>

using namespace std;

const int MAX = 101;

int trash[MAX][MAX]; // 쓰레기 위치 
bool visited[MAX][MAX]; // 방문 여부 

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int cnt;

int DFS(int x, int y)
{
	visited[x][y] = true;
	
	for(int i = 0; i < 4; i++)
	{
		int ax = dx[i] + x;
		int ay = dy[i] + y;
		
		if(ax <= 0 || ay <= 0 || ay > 101 || ax > 101 || visited[ax][ay] == true)
		continue;
		
		if(trash[ax][ay] == 1)
		{
			visited[ax][ay] = true;
			cnt++;
			DFS(ax, ay);
		}
	}

}

int main()
{
	int N, M, K;
	int r, c;
	int ans;
	
	cin >> N >> M >> K;
	
	for(int i = 0; i < K; i++)
	{
		cin >> r >> c;
		trash[r][c] = 1;
	}
	
	for(int j = 1; j <= N; j++)
	{
		for(int k = 1; k <= M; k++)
		{
			DFS(j, k);
			if(ans < cnt)
			ans = cnt;
		}
	}
	
	cout << ans;
	
}
