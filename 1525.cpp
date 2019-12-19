#include <iostream>
#include <queue>
#include <map>
#include <string>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int main()
{
	int start = 0;
	
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			int num;
			cin >> num;
		
			if(num == 0)
			num = 9;
		
			start = start * 10 + num;	
		}

	}
	
	queue<int> q;
	map<int, int> visited;
	visited[start] = 0;
	q.push(start);
	
	while(!q.empty())
	{
		int cur = q.front();
		string s = to_string(cur);
		q.pop();
		
		int z = s.find('9');
		int x = z / 3;
		int y = z % 3;
		
		for(int k = 0; k < 4; k++)
		{
			int next_x = x + dx[k];
			int next_y = y + dy[k];
			
			if(next_x >= 0 && next_x < 3 && next_y >= 0 && next_y < 3)
			{
				string next = s;
				swap(next[3 * x + y], next[3 * next_x + next_y]);
				int next_num = stoi(next);
				if(visited.count(next_num) == 0)
				{
					visited[next_num] = visited[cur] + 1;
					q.push(next_num);
				}
			}
		}
	}
	
	if(visited.count(123456789) == 0)
	{
		cout << -1;
	}
	else
	cout << visited[123456789];
}
