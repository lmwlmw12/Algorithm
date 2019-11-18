#include<iostream>
#include <vector>
#include<algorithm>

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int group[26][26];
bool visited[26][26];
int territory;

std::vector<int> territory_num;
int count = 0;

int DFS(int x, int y) {
	
	
	visited[x][y] = true;
	
	for(int i = 0; i < 4; i++) {
		int ax = x + dx[i];
		int ay = y + dy[i];
		
		if(ax <= 0 || ay <= 0 || ax > territory || ay > territory || visited[ax][ay]) {
			continue;
		}
		
		if(group[ax][ay] == 1) {
			count++;
			DFS(ax, ay);
		}
		
	}
}

int main() {
		
	int sum_territory = 0;
	std::cout << "총 단지수 출력 : ";
	std::cin >> territory;
	while(territory <= 4) {
		std::cout << "다시 입력 : ";
		std::cin >> territory;
	}
	
	for(int i = 1; i <= territory; i++) {
		for(int j = 1; j <= territory; j++) {
			scanf("%1d", &group[i][j]);
		}

	}
	
	for(int i = 1; i <= territory; i++) {
		for(int j = 1; j <= territory; j++) {
			if(group[i][j] == 1 && visited[i][j] == false) {
				count = 0;
				DFS(i, j);
				sum_territory++;
				territory_num.push_back(count);
			}
		}
	}
	sort(territory_num.begin(), territory_num.end());
	
	std::cout << sum_territory << std::endl;
	for(int i = 0; i < sum_territory; i++) {
		std::cout << territory_num[i]+1 << std::endl;
	}
	
	
	
}
