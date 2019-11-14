#include<iostream>



int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool visited[101][101];
int trash_location[101][101];
int N, M, K;
int count= 0;

int Init_trash() {
	for(int i = 1; i < 101; i++) {
		for(int j = 1; j < 101; j++) {
			trash_location[i][j] = 0;
		}
	}
}

int DFS(int x, int y) {
	
	visited[x][y] = true;
	
	for(int i = 0; i < 4; i ++) {
		int ax = x + dx[i];
		int ay = y + dy[i];
		
		if(ax <= 0 || ay <= 0 || ax > N || ay > M || visited[ax][ay]) {
			continue;
		}
		
		if(trash_location[ax][ay] == 1) {
			count++;
			DFS(ax, ay);
		}
	}
	
}

int main() {
	
	int r, c;
	int ans = 0;
	std::cout << "세로 가로 개수 입력 :";
	std::cin >> N >> M >> K;
	Init_trash(); 
	for(int i =0; i < K; i++) {
		std::cout << "좌표 입력 :";
		std::cin >> r >> c;
		trash_location[r][c] = 1;
	}
	
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= M; j ++) {
			if(trash_location[i][j] == 1 && visited[i][j] == false) {
				DFS(i, j);
				if(ans < count) {
					ans = count;
				}
			}
		}
	}
	std::cout << "가장 큰 음식물 : ";
	std::cout << ans+1;
	
}
