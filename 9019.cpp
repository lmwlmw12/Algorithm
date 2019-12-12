#include <iostream>
#include <deque>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 10000;

int A, B;
bool visited[MAX];

deque<int> Dq;
queue<pair<int, string> > Aq;

string BFS() {
	
	Aq.push({A, ""});
	visited[A] = true;
	
	while(!Aq.empty())
	{
		int cur = Aq.front().first;
		string cnt = Aq.front().second;
		Aq.pop();
		
		if(cur == B) {
			return cnt;
		}
		
		// D
		int D = cur;
		D *= 2;
		
		if( D > 9999)
		{
			D %= 10000;
		}
		
		if(!visited[D])
        {
            visited[D] = true;
            Aq.push({D, cnt + "D"});
        }
		
		// S
		int S = cur;
		S -= 1;
		
		if(S == 0)
		{
			S = 9999;
		}
		
		if(!visited[S])
        {
            visited[S] = true;
            Aq.push({S, cnt + "S"});
        }
		
		// L
		int L;
		L = (cur % 1000) * 10 + cur / 1000;
		
		if(!visited[L])
        {
            visited[L] = true;
            Aq.push({L, cnt + "L"});
        }
		
		
		// R
		int R;
		R = (cur % 10) * 1000 + (cur / 10);
		
		if(!visited[R])
        {
            visited[R] = true;
            Aq.push({R, cnt + "R"});
        }
	}
	
}

int main () {
	
	int T;
	
	cin >> T;
	
	while(T>0)
	{
		memset(visited, false, sizeof(visited));
		cin >> A >> B;
	
		cout << BFS();
		T--;
	}
	
	
	
}
