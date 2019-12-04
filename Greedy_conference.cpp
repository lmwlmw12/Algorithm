#include<iostream>
#include<vector>

using namespace std;

int main () {
	
	int N;
	int one, two;
	int count = 0;
	int result = 0;
	int result_two = -1;
	vector<pair<int, int> > pv;
	
	cin >> N;
	
	for(int i = 0; i < N; i++) {
		
		cin >> one >> two;
		pv.push_back(make_pair(one, two));
	}
	
	while(result_two != 0) {
				
		for(int i = 0; i < N; i++) {
			
			if(pv[i].second == count) {
				result_two--;
				
			}

			if(pv[i].first == count) {
				if(result_two == -1) {
					result_two++;
				}
				result_two++;
				
			}
			
			if(result_two > result) {
					result = result_two;			
				}
				
	
			
		}
		count++;
	}
	
	cout << result;
}
