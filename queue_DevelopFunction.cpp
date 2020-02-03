#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
	vector<int> answer;
	queue<pair<int, int> > q;
	queue<int> count;
	
	for(int i = 0; i < progresses.size(); i++)
	{
		q.push({progresses[i], speeds[i]});
	}
	
	while(!q.empty())
	{
		int cnt = 0;
		int de = q.front().first;
		int spe = q.front().second;
		
		while(de < 100)
		{
			de += spe;
			cnt++;
		}
		
		q.pop();
		count.push(cnt);
		cout << count.back() << endl;	
	}
	
	int res = 1;
	int num = count.front();
	count.pop();
	while(!count.empty())
	{
		int com = count.front();
		count.pop();
		
		if(num > com)
		{
			res++;
		}
		else
		{
			answer.push_back(res);
			res = 1;
			num = com;
			
		}
		
		if(count.empty())
		{
			answer.push_back(res);
		}
		
	}
	
	return answer;
}

int main()
{
	int develop_function = 0;
	vector<int> progress;
	vector<int> speed; 
	
	cout << "기능 개수 :"; 
	cin >> develop_function;
	
	for(int i = 0; i < develop_function; i++)
	{
		int pro;
		cin >> pro;
		progress.push_back(pro);
	}
	
	cout << "스피드 : "; 
	
	for(int j = 0; j < progress.size(); j++)
	{
		int sp;
		cin >> sp;
		speed.push_back(sp);
	}
	
	vector<int> result;
	result = solution(progress, speed);
	
	for(int k = 0; k < result.size(); k++)
	{
		cout << result[k] << " ";
	}
}
