#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> heights)
{
    vector<int> answer;
    stack<pair<int, int> > transmit;
    stack<pair<int, int> > receive;
    
    for(int i = 0; i < heights.size(); i++)
    {
    	transmit.push({heights[i], i+1});
	}
	
	while(!transmit.empty())
	{
		int number = transmit.top().first;
		transmit.pop();
	
		for(int j = transmit.size(); j >= 0; j--)
		{
			int tmp = heights[j];
			if(tmp > number)
			{
				receive.push({number, j+1});
				break;
			}
			if(j == 0)
			{
				receive.push({number, 0});
			}
		}
	}
	
	while(!receive.empty())
	{
		answer.push_back(receive.top().second);
		receive.pop();
	}
    
    return answer;
}

int main()
{
	vector<int> v;
	vector<int> result;
	int cnt = 0;
	
	cout << "타워 개수 :";
	cin >> cnt;
	
	for(int i = 0; i < cnt; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}
	
	result = solution(v);
	
	for(int j = 0; j < result.size(); j++)
	{
		cout << result[j] << " ";
	}
}
