#include <iostream>
#include <algorithm>

using namespace std;

int N;
int crossAr[100000];
int leftAr[99999];
int rightAr[99999];

long long leftSum;
long long rightSum;

long long answer = 0;
int idx;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> crossAr[i];
	for(int i = 0; i < N-1; i++)
		cin >> leftAr[i];
	for(int i = 0; i < N-1; i++)
		cin >> rightAr[i];
	for(int i = 0; i < N-1; i++)
		rightSum += rightAr[i];
	
	answer = leftSum + rightSum + crossAr[0];
	idx = 1;
	for(int i = 0; i < N-1; i++)
	{
		leftSum += leftAr[i];
		rightSum -= rightAr[i];
		long long curDistance = leftSum + rightSum + crossAr[i+1] ;
		if(curDistance < answer)
		{
			answer = curDistance;
			idx = i+2;
		}
	}
	cout << idx << " " << answer << endl;
}