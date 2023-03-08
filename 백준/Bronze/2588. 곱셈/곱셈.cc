#include <iostream>
#include <string>

using namespace std;

int main()
{
	string A, B;
	cin >> A >> B;
	int final_answer = 0;
	int final_base = 1;
	for(int i = 2; i >= 0; i --)
	{
		int answer = 0;
		int base = 1;
		int cur_B = B.at(i) - '0';
		for(int j = 2; j >= 0; j --)
		{
			int cur_A = A.at(j) - '0';
			answer += cur_B * base * cur_A;
			base = base * 10;
		}
		cout << answer << endl;
		final_answer += final_base * answer;
		final_base *= 10;
	}
	cout << final_answer << endl;
}	