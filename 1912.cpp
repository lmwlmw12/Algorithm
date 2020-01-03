#include <iostream>

using namespace std;

int main ()
{
	int n, result;
	int tmp = -1000;
	
	cin >> n;
	
	int num[n];
	
	for(int i = 0; i < n; i++)
	{
		cin >> num[i];
	}
	
	for(int j = 0; j < n; j++)
	{
		for(int k = j+1; k < n; k++)
		{
			result = num[j] + num[k];
			if(tmp < result)
			{
				tmp = result;
			}
		}
	}
	
	cout << tmp;
}
