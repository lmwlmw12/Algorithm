#include <iostream>

using namespace std;

int main ()
{
	int N, M, tree[100000];
	
	cin >> N >> M;
	
	for(int i = 0; i < N; i++)
	{
		cin >> tree[i];
	}
	
	int min = 0;
	int max = 1000000000;
	
	while(min + 1 < max)
	{
		int mid = (min + max) / 2;
		
		long long sum = 0;
		
		for(int j = 0; j < N; j++)
		{
			if(tree[j] > mid)
			{
				sum += tree[j] - mid;
			}
		}
		
		if(sum >= M)
		{
			min = mid;
		}
		else
		max = mid;
	}
	
	cout << min;
}
