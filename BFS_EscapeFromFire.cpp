#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

#define MAX_SIZE 1000

bool visited[MAX_SIZE][MAX_SIZE];
char location[MAX_SIZE][MAX_SIZE];

queue<pair<int, int> > q;
queue<pair<int, int> > fire_q;

int direction_w[] = {-1, 0, 1, 0};
int direction_h[] = {0, 1, 0, -1};

int w, h;

int BFS(int width, int height) {
	
	int count = 0;
	visited[width][height] = true;
	q.push(pair<int, int>(width, height));
	
	while(!q.empty()) {
		
		int flame_size = fire_q.size();
		
		for(int i = 0; i < flame_size; i++) {
			
			int curr_f_w = fire_q.front().first;
			int curr_f_h = fire_q.front().second;
			fire_q.pop();
			
			for(int i = 0; i < 4; i++) {
				int after_f_w = curr_f_w + direction_w[i];
				int after_f_h = curr_f_h + direction_h[i];
				
				if(after_f_w < 0 || after_f_h < 0 || after_f_w >= w || after_f_h >= h || location[after_f_w][after_f_h] == '#') {
					continue;
				}
			
				if(location[after_f_w][after_f_h] == '.') {
					location[after_f_w][after_f_h] = '*';
					fire_q.push(pair<int,int>(after_f_w, after_f_h));
					
				}
			}
		}
		
		for(int i = 0; i < q.size(); i++) {
			
			int curr_w = q.front().first;
			int curr_h = q.front().second;
			q.pop();
		
			if(curr_w == 0 || curr_h == 0 || curr_w == w - 1 || curr_h == h - 1) {
				return count+1;
			}
		
			for(int i = 0; i < 4; i++) {
				int after_w = curr_w + direction_w[i];
				int after_h = curr_h + direction_h[i];
			
				if(after_w < 0 || after_h < 0 || after_w >= w || after_h >= h || visited[after_w][after_h]) {
					continue;
				}
			
				if(location[after_w][after_h] == '.') {
					visited[after_w][after_h] = true;
					q.push(pair<int, int>(after_w, after_h));
				}		
			
			}
		
			count++;
			}
		}
		
		
	return -1;
}

int main() {
	
	int T;
	
	int result;
	
	cout << "테스트 케이스 : ";
	cin >> T; 
	
	while(T>0) {
		
		int x, y;
		
		cin >> w >> h;
		
		for(int i = 0; i < w; i++) {
			for(int j = 0; j < h; j++) {
				cin >> location[i][j];
				if(location[i][j] == '@') {
					x = i;
					y = j;
				}
				if(location[i][j] == '*') {
					fire_q.push(pair<int, int>(i, j));
				}
			}
		}
		
		result = BFS(x, y);
		if(result == -1) {
			cout << "IMPOSSIBLE" << endl;

		}
		else
		cout <<	result << endl;
		
		T--;
	}
}
