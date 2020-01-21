#include <iostream>
#include <vector>
#include <string>

using namespace std;

int solution (vector<string> phone_book)
{
	bool answer = true;
	
	for(int i = 0; i < phone_book.size(); i++)
	{
		for(int j = i+1; j < phone_book.size(); j++)
		{
			string cnt = phone_book[i];
			string cnt2 = phone_book[j];
			if(cnt2.find(cnt) != string::npos)
			{
				answer = false;
				return answer;
			}
			
		}
	}

	return answer;
}

int main ()
{
	vector<string> v;
	
	int number = 0;
	
	cin >> number;
	
	for(int i = 0; i < number; i++)
	{
		string num;
		cin >> num;
		v.push_back(num);
	}
	
	bool res = solution(v);
	
	if(res == false)
	{
		cout << "false";
	}
	else
	cout << "true";
}
