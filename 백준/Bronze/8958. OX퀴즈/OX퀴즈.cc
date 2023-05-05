#include <iostream>
#include <string>

using namespace std;


int main()
{
	int N;
	cin >> N;
	for(int i = 0; i < N; i ++)
	{
		string str;
		cin >> str;
		int score = 0;
		int tmp_score = 0;
		for(int i = 0; i < str.size(); i++)
		{
			if(str[i] == 'O')
			{
				tmp_score ++;
				score += tmp_score;
			}
			else
			{
				tmp_score = 0;
			}
		}
		cout << score << "\n";
	}
}