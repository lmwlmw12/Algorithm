#include<iostream>

using namespace std;



int main() {
	
	int N, K;
	int result = 0;
	int count = 0;
	
	
	cin >> N >> K;
	
	int coin[N];
	
	for(int i = 0; i < N; i++) {
		
		cin >> coin[i];
	}
	
	result = K;
	
//	while(result != 0) {
		
		for(int i = N-1; i >= 0; i--) {
			
			if(result / coin[i] != 0) {
				
				count += result / coin[i];
				result = result % coin[i];
			} 
		}
	//}
	
	cout << count << endl;
	
}
