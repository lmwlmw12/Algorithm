#include <iostream>
#include <queue>

using namespace std;

const int MAX = 100000;

int N, T, G;
bool visited[MAX];


int BFS(void)
{
	
	queue<pair<int, int> > q;
	q.push({N, 0});
	visited[N] = true;
	
	while(!q.empty())
	{
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();
		
		if(cnt > T)
		{
			break;
		}		
		
		if(cur == G)
		{
			return cnt;
		}
		
		
		int A = cur + 1;
		
		if(A < MAX && !visited[A])
		{
			visited[A] = true;
			q.push({A, cnt+1});
		}
		
		int B = cur * 2;
		if(B >= MAX)
		continue;
		
		int temp = B;
		int digit = 1;
		while(temp >= 1)
		{
			if(temp / 10 == 0)
			{
				break;
			}
			
			temp /= 10;
			digit *= 10;	
		}
		
		B -= digit;
		
		
		if(B < MAX && !visited[B])
		{
			visited[B] = true;
			
			q.push({B, cnt + 1});
		}
	}
	
	return -1;
}

int main ()
{
	
	cin >> N >> T >> G;
	int res = BFS();
;
	
	if( res == -1)
	{
		cout << "ANG";
	}
	else
	cout << res;
}
