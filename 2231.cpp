#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int num, result;
	vector<int> v;
	cin >> num;
	
	for(int i = 1; i < num; i++)
	{
		int tmp = i;
		
		while(tmp > 0)
		{
			int cnt = tmp%10;
			
			
			if(tmp > 10)
			{
				v.push_back(cnt);
			}
			else
			{
				v.push_back(cnt);
				break;
			}
			
			tmp /= 10;
		}
		
		for(int j = 0; j < v.size(); j++)
		{
			result += v[j];
		}
		
		if(result + i == num)
		{
			cout << i << endl;
			break;
		}
		
		result = 0;
		v.clear();
	}
	
}
