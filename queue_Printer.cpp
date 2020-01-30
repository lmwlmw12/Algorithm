#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location)
{
	int answer = 0;
	queue<pair<int,int> > q;
	int most = 0;
	int cnt = 1;
	
	for(int i = 0; i < priorities.size(); i++)
	{
		q.push({priorities[i], i});
		if(most < priorities[i])
		{
			most = priorities[i];
		}
	}
	
	while(!q.empty())
	{
		
		for(int j = 0; j < q.size(); j++)
		{
			int tmp = q.front().first;
			int locat = q.front().second;
			if(most == tmp)
			{
				if(location == locat)
				{
					answer = cnt;
					return answer;
				}
				q.pop();
				most = 0;
				cnt++;
				break;
			}
			q.pop();
			q.push({tmp, locat});
		}
				
		for(int k = 0; k < q.size(); k++)
		{
			
			int tmp = q.front().first;
			int locat = q.front().second;
			if(most < tmp)
			{
				most = tmp;		
			}
			q.pop();
			q.push({tmp, locat});
		}
		
	}
	
	answer = -1;
	
	return answer;
}

int main()
{
	vector<int> pr;
	int lct, cnt;
	
	
	cout << "°³¼ö : ";
	cin >> cnt;
	
	for(int i = 0; i < cnt; i++)
	{
		int num;
		cin >> num;
		pr.push_back(num);
	}
	
	cout << "lcoation : ";
	cin >> lct;
	
	int result = solution(pr, lct);
	
	cout << result;
}
