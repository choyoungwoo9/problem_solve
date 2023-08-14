#include <iostream>
#include <vector>
#include <string>

using namespace std;

int flag = 0;
vector<int> answer;

void getSum(string &A, string &B)
{
	int gap = (int)A.size() - (int)B.size();
	for(int i = 0; i < gap; i++)
		answer.push_back(A[i]-'0');
	for(int i = 0; i < B.size(); i++)
		answer.push_back(A[i+gap]+B[i]-'0'-'0');
	for(int i = answer.size(); i > 0; i--)
	{
		if(answer[i] >= 10)
		{
			answer[i] -= 10;
			answer[i-1] ++;
		}
	}
	if(answer.size() && answer[0] >= 10)
	{
		answer[0] -= 10;
		flag = 1;
	}
}

int main()
{
	string A, B;
	cin >> A >> B;
	if(A.size() > B.size())
		getSum(A, B);
	else
		getSum(B, A);
	if(flag)
		cout << "1";
	for(int i = 0; i < answer.size(); i++)
		cout << answer[i];
	cout << endl;
}