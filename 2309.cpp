#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main ()
{
	vector<int> v;
	int sum = 0;
	
	for(int i = 0; i < 9; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
		sum += num;
	}
	
	sort(v.begin(), v.end());
	
	for(int j = 0; j < 9; j++)
	{
		for(int k = j+1; k < 9; k++)
		{
			if(sum - v[j] - v[k] == 100)
			{
				for(int l = 0; l < 9; l++)
				{
					if(l != j && l != k)
					{
						cout << v[l] << endl;
					}
				}
			}
		}
	}
}
