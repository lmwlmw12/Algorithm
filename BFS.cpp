#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

bool visited[1001];
int adj[1001][1001];
queue<int> Q;
int N, M, V;

int BFS(int idx) {
	
	Q.push(idx);
	visited[idx] = true;
	
	while(!Q.empty()) {
		idx = Q.front();
		Q.pop();
		
		cout << idx ;
		
		for(int i = 1; i <= N; i++) {
			if(!visited[i] && adj[idx][i]) {
				visited[i] = true;
				Q.push(i);
			}
		}
	}
}

int main() {
	
	int from, to;
	
	cin >> N >> M >> V;
	
	for(int i = 0; i < M; i++) {
		std::cin >> from >> to;
		adj[from][to] = 1;
		adj[to][from] = 1;
	}

	BFS(V);
	cout << endl;
}
