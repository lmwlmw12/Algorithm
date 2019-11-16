#include<stdio.h>

#define MAX_LENGTH 50
#define NUM 2500


int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

bool visited[MAX_LENGTH][MAX_LENGTH];

int count = 0;
int N, M, K;
int X, Y;
int cabbage_location[MAX_LENGTH][MAX_LENGTH];

int Init_location() {
	
	for(int i = 0; i < MAX_LENGTH; i++) {
		
		for(int j = 0; j < MAX_LENGTH; j++) {
			
			cabbage_location[i][j] = 0;
		}
	}
}

int DFS(int x, int y) {
	if(visited[x][y]) {
		return 0;
	}
	
	visited[x][y] = true;
	
	for(int i = 0; i < 4; i++) {
		int ax = x + dx[i];
		int ay = y + dy[i];
	
	
	if(ax < 0 || ay < 0 || ax >= N || ay >= K) {
		continue;
	}
	
	if(!cabbage_location[ax][ay] == 0 || visited[ax][ay]) {
		DFS(ax, ay);
	}
	
	}
	
	
}

int main() {
	
	int T;
	scanf("%c", &T);
	
	while(T>0) {
		
		printf("배추 가로 세로 개수 입력 : ");
		scanf("%d %d %d", &N, &M, &K);
		for(int i = 0; i < K; i++) {
			printf("배추 좌표 입력: ");
			scanf("%d %d", &X, &Y);
			cabbage_location[X][Y] = 1;
		}
		
		for(int i = 0; i < N; i++) {
		
		for(int j = 0; j < K; j++) {
			
			if(cabbage_location[i][j] == 1 && visited[i][j] == false) {
				count++;
				DFS(i, j);
			}
		}
			
	}

		printf("%d", count);
		T--;
	}
}
