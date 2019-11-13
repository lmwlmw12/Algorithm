#include<iostream>
#include<vector>

using namespace std;

#define MAX_SIZE 1001


vector<int> a[MAX_SIZE];
bool visited[MAX_SIZE];

int DFS(int node) {
	
	visited[node] = true;
	
	for(int i = 0; i < a[node].size(); i++) {
		
		int next = a[node][i];
		if(visited[next] == false) {
			DFS(next);
		}
	}	
}

int main() {
	
	int N, M, ans;
	std::cin >> N >> M;
	
	int u, v;
	
	
	for(int i = 0; i < M; i ++) {	
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	
	for(int j = 1; j <= N; j++) {
		
		if(visited[j] == false) {
			DFS(j);
			ans++;	
		}
		
	}
	
	std::cout << ans << "\n";
	
	return 0;
}
