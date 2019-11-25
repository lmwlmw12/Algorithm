#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

queue<pair<pair<int, int>, int> > q;

#define MAX_SIZE 30

bool visited[MAX_SIZE][MAX_SIZE][MAX_SIZE];
char location[MAX_SIZE][MAX_SIZE][MAX_SIZE];
int cur[MAX_SIZE][MAX_SIZE][MAX_SIZE];

int dx[] = {-1, 0, 1, 0, 0, 0};
int dy[] = {0, 1, 0, -1, 0, 0};
int dz[] = {0, 0, 0, 0, -1, 1};

int L, R, C;

int BFS() {
	
	int x, y, z;
	
	for(int i = 0; i < L; i++) {
		for(int j = 0; j < R; j ++) {
			for(int k = 0; k < C; k++) {
				if(location[j][k][i] == 'S') {
					x = j;
					y = k;
					z = i;
					break;
				}
			}
		}
	}
	
	visited[x][y][z] = true;
	q.push({{x, y}, z});
	
	while(!q.empty()) {
		
		int curr_x = q.front().first.first;
		int curr_y = q.front().first.second;
		int curr_z = q.front().second;
		q.pop();
		
		for(int i = 0; i < 6; i++) {
		int ax = curr_x + dx[i];
		int ay = curr_y + dy[i];
		int az = curr_z + dz[i];
		
			if(ax < 0 || ay < 0 || az < 0 || ax > R || ay > C || az > L || visited[ax][ay][az]) {
				continue;
			}
		
			if(location[ax][ay][az] == '.' || location[ax][ay][az] == 'E') {
				visited[ax][ay][az] = true;
				cur[ax][ay][az] = cur[curr_x][curr_y][curr_z] + 1;
				q.push({{ax,ay},az});
			}
		
		}
	}	
		
}

int main() {
	
	cout << "L R C ют╥б : ";
	cin >> L >> R >> C;
	
	for(int i = 0; i < L; i++) {
		for(int j = 0; j < R; j ++) {
			for(int k = 0; k < C; k++) {
				cin >> location[j][k][i];
			}
		}
	}
	
	BFS();
	for(int i = 0; i < L; i++) {
		for(int j = 0; j < R; j ++) {
			for(int k = 0; k < C; k++) {
				if(location[j][k][i] == 'E') {
					cout << cur[j][k][i];
				}
			}
		}
	}
}
