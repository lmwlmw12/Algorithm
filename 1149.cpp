#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 1000

int N;
int cost[1000][3];
int dp[1000][4];

int RGB(int cur, int prev = 3) {

	int& result = dp[cur][prev];
	
	if(result != -1) {
		return result;
	}
	if(cur == N) {
		return result = 0;
	}
	result = MAX;
	for(int i = 0; i < 3; i++) {
		if(prev != i) {
			result = min(result, RGB(cur+1, i) + cost[cur][i]);
		}
	}
	return result;
	
}

int main () {
	
	cin >> N;
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < 3; j++) {
			scanf("%d", &cost[i][j]);
		}
	}
	
	memset(dp, -1, sizeof(dp));
	
	cout << RGB(0);

}

