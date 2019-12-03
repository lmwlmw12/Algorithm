#include<iostream>

using namespace std;

int main() {
	
	int count = 1;
	int L, P, V;
	int divide_result;
	int rest_result;
	int result;
	
	cin >> L >> P >> V;
	
	divide_result = V/P;
	rest_result = (V%P) > L ? L : V%P;
	result = divide_result*L + rest_result;
	
	cout << "CASE " << count++ << ": " << result << endl;
	
}
