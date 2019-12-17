#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

#define MAX 10001

int n;
int weight[MAX];
vector<int> weight_dot[MAX];
vector<int> node[MAX];
bool visited[MAX];
int dp[MAX][2];

void DFS(int cur) {
	visited[cur] = true;
	for(int i = 0; i < weight_dot[cur].size(); i++) {
		
		int next = weight_dot[cur][i];
		
		if(!visited[next]) {
			
			node[cur].push_back(next);
			DFS(next);
		}
	}
}

int most_result(int cur, bool deserve) {
	
	int& result = dp[cur][deserve];
	if(result != -1) {
		return result;
	}
	
	if(deserve) {
		result = weight[cur];
		for(int i = 0; i < node[cur].size(); i++) {
			int next = node[cur][i];
			cout << cur << endl;
			result += most_result(next, false);
		}
	}	
	else {
		result = 0;
		for(int j = 0; j < node[cur].size(); j++) {
			int next = node[cur][j];
			result += max(most_result(next, true), most_result(next, false));
		}
	}
	
	return result;
	
}

int main() {
	
	int x, y;
	
	cin >> n;
	
	for(int i = 1; i <= n; i++) {
		cin >> weight[i];
	}
	
	for(int j = 0; j < n-1; j++) {
		cin >> x >> y;
		
		weight_dot[x].push_back(y);
		weight_dot[y].push_back(x); 
	}
	
	memset(dp, -1, sizeof(dp));
	
	DFS(1);
	
	cout <<  max(most_result(1, true), most_result(1, false));
	
	return 0;
	
}
