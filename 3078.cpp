#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

const int MAX = 300000;

vector<int> name_length[MAX];

int main() {
	
	int N, K;
	int res;
	string name;
	cin >> N >> K;
	for(int i = 1; i <= N; i++) {
		cin >> name;
		name_length[name.size()].push_back(i);
	
	}
	
	for(int j = 1; j <= 20; j++) {
		sort(name_length[j].begin(), name_length[j].end());
		for(int k = 0; k < name_length[j].size(); k++){
            if(name_length[j][k] + K > name_length[j][k+1] && name_length[j][k+1] != 0) {
            	res += 1;
			}
		}
		

	}
	
	cout << res;
	
}
