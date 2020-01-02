#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 101;

int N, M, K;

bool visited[MAX][MAX];
bool drew[MAX][MAX];
vector<int> v;
int cnt;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int DFS (int y, int x)
{
	visited[y][x] = true;
	cnt++;
	
	for(int i = 0; i < 4; i++)
	{
		int ax = x + dx[i];
		int ay = y + dy[i];
		
		if(0 <= ay && ay < M && 0 <= ax && ax < N)
		{
			if(!visited[ay][ax] && !drew[ay][ax])
			{
				DFS(ay, ax);
			}
		}

	}
	
}

int main ()
{	
	int x_one, y_one, x_two, y_two;
	
	cin >> M >> N >> K;
	
	for(int i = 0; i < K; i++)
	{
		cin >> x_one >> y_one >> x_two >> y_two;

		for(int a = y_one; a < y_two; a++)
		{
			for(int b = x_one; b < x_two; b++)
			{
				drew[a][b] = true;
			}
		}
	}
	
	for(int j = 0; j < M; j++)
	{
		for(int k = 0; k < N; k++)
		{
			if(drew[j][k] == false && visited[j][k] == false)
			{
				cnt = 0;
				DFS(j, k);
				v.push_back(cnt);
			}		
		}
	}
	
	cout << v.size() << endl;
	
	sort(v.begin(), v.end());
	
	for(int l = 0; l < v.size(); l++)
	{
		cout << v[l] << " ";
	}
}
