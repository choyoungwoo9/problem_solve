#include <iostream>
#include <string>

using namespace std;

int main()
{
	int N;
	cin >> N;
	string input;
	cin >> input;
	int answer = 0;
	for(int i = 0; i < input.length(); i ++)
		answer += (input.at(i) - '0');
	cout << answer << endl;
}