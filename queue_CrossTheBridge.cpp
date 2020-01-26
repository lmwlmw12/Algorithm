#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution (int bridge_length, int weight, vector<int> truck_weights) 
{
    int answer = 0;
    queue<pair<int, int> > m;
    queue<pair<int, int> > w;
	int total_weight = 0;
	
	for(int i = 0; i < truck_weights.size(); i++)
	{
		w.push({truck_weights[i], 0});
	}

    m.push({w.front().first, w.front().second});
    
    total_weight += m.front().first;
    w.pop();
    
    while(!m.empty())
    {
    	
    	answer++;
    	
    	for(int j = 0; j < m.size(); j++)
		{
			int now = m.front().first;
			int time = m.front().second;
			time++;
			m.pop();
			m.push({now, time});
		}
		
		if(m.front().second > bridge_length)
		{
			total_weight -= m.front().first;
			m.pop();
		}
		
		if(!w.empty() && total_weight + w.front().first <= weight)
		{
			total_weight += w.front().first;
			w.front().second++;
			m.push({w.front().first, w.front().second});
			w.pop();
		}
		
	}
    
    
    return answer;
}

int main ()
{
	int length, w, cnt;
	vector<int> tw;
	
	cout << "다리 길이 :"; 
	cin >> length;
	
	cout << "무게 :" ;
	cin >> w;
	
	cout << "트럭 개수 :";
	cin >> cnt;
	
	for(int i = 0; i < cnt; i++)
	{
		int num;
		cin >> num;
		tw.push_back(num);
	}
	
	int result = solution(length, w, tw);
	
	cout << result;
}
