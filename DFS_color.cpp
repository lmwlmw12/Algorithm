#include<iostream>
#include<algorithm>

#define MAX_SIZE 100


int N;
int visited[MAX_SIZE][MAX_SIZE];
char color[MAX_SIZE][MAX_SIZE];
int count_red = 0;
int count_blue = 0;
int count_green = 0;
int count_red_green = 0;


int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int DFS(int x, int y, char inColor, int color_weakness) {
	
	visited[x][y] = true;
	
	for(int i =0; i < 4; i++) {
		int ax = x + dx[i];
		int ay = y + dy[i];
		
		if(ax < 0 || ay < 0 || ax > N || ay > N || visited[ax][ay]) {
			continue;
		}
		
		if(color_weakness == 0) {
			
			if(color[ax][ay] == 'R' && color[ax][ay] == inColor) {
				DFS(ax, ay, inColor, color_weakness);
			}
			if(color[ax][ay] == 'G'  && color[ax][ay] == inColor) {
				DFS(ax, ay, inColor, color_weakness);
			}
		
		}
		
		if(color_weakness == 1) {
			
			if(color[ax][ay] != 'B') {
				DFS(ax, ay, inColor, color_weakness);
			}
		}
		
		if(color[ax][ay] == 'B' && color[ax][ay] == inColor) {
			DFS(ax, ay, inColor, color_weakness);
		}
	}
} 

int main() {
	
	int color_classification = 0;
	
	std::cout<<"입력: ";
	std::cin >> N;
	while(N < 0 || N > 100) {
		std::cout << "다시 입력";
		std::cin >> N;
	}
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			std::cin >> color[i][j];
		}
	}
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			if(color[i][j] == 'R' && !visited[i][j]) {
				DFS(i, j, color[i][j], color_classification);
				count_red++;
			}
			if(color[i][j] == 'G' && !visited[i][j]) {
				DFS(i, j, color[i][j], color_classification);
				count_green++;
			}
			if(color[i][j] == 'B' && !visited[i][j]) {
				DFS(i, j, color[i][j], color_classification);
				count_blue++;
			}
		}
	}
	
	std::cout << count_red + count_green + count_blue << std::endl;
	
	color_classification = 1;
	//count_blue = 0;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j <N; j++) {
			visited[i][j] = false;
		}
	}
	
	for(int i =0; i < N; i++) {
		for(int j =0; j < N; j++) {
			if(color[i][j] == 'R' || color[i][j] == 'G' && !visited[i][j]) {
				DFS(i, j, color[i][j], color_classification);
				count_red_green++;
			}
			
			/*if(color[i][j] == 'B' && !visited[i][j]) {
				DFS(i, j, color[i][j], color_classification);
				count_blue++;
			}*/
		}
	}
	std::cout << count_red_green << std::endl;
	std::cout << count_blue;
	//std::cout << count_red_green + count_blue;
	
}
