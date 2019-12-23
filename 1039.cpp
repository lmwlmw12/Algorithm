#include <iostream>
#include <queue>
#include <cstdio>

using namespace std;

int M;

int digit(int n, int i){
    for(int k=0; k<i; k++) n /= 10;
    return n%10;
}

int swap_num(int num, int i, int j)
{
	char tmp[8];
	sprintf(tmp, "%d", num);
	swap(tmp[M-i-1], tmp[M-j-1]);
	sscanf(tmp, "%d", &num);
	return num;
}

int main()
{
	int N, K;
	queue<int> q;
	
	cin >> N >> K;
	
	q.push(N);
	
	while(N != 0)
	{
		M++;
		N /= 10;
	}
	
	for(int i = 0; i < K; i++)
	{
		int qsize = q.size();
		bool visited[1000001] = {0};
		
		for(int j = 0; j < qsize; j++)
		{
			int cur = q.front();
			q.pop();
			
			for(int k = 0; k < M-1; k++)
			{
				for(int l = k+1; l < M; l++)
				{
					if(l < M-1 || digit(cur, k))
					{
						int swap_result = swap_num(cur, k, l);
						if(!visited[swap_result])
						{
							visited[swap_result] = true;
							q.push(swap_result);
						}
					}
					
				}
			}
		}
	}
	
	int result = -1;
	
	while(!q.empty())
	{
		result = max(result, q.front());
		q.pop();
	}
	cout << result;
	
}
