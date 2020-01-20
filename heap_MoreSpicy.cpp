#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> sco;
priority_queue<int, vector<int>, greater<int> > pq;

int solution(vector<int> scoville, int K)
{
	int answer = 0;
	
	int least_one, least_two;
	
	for(int i = 0; i < scoville.size(); i++)
	{
		pq.push(scoville[i]);
	}
	
	int sum = 0;
	
	while(K > sum)
	{
		
		if(pq.size() == 1)
		{
			return -1;
		}
		
		least_one = pq.top();
		pq.pop();
		least_two = pq.top();
		pq.pop();
		
		
		sum = least_one + (least_two * 2);
		
		pq.push(sum);
		answer++;
		
	}
	
	return answer;
}

int main()
{
	int K = 0;
	int cnt = 0; 
	cout << "음식 개수 :";
	cin >> cnt;
	for(int i = 0; i < cnt; i++)
	{
		int food;
		cin >> food;
		sco.push_back(food);
	}
	
	cin >> K;
	
	int result = solution(sco, K);
	
	cout << result;
}
