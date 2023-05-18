#include <iostream>
#include <algorithm>

using namespace std;

int k;
int ar[14];

int ar2[14];

void recursive_print(int num)
{
	if(num < 10)
	{
		cout << ar[num] << " ";
		return ;
	}
	recursive_print(num / 10);
	cout << ar[num % 10] << " ";
}



void recursive_make(int cur_num, int count)
{
	if(count == 6)
	{
		for(int i = 0; i < 6; i ++)
			cout << ar[ar2[i]] << " ";
			cout << "\n";
		return ;
	}
	for(int i = cur_num; i <= k; i ++)
	{
		ar2[count] = i;
		recursive_make(i+1, count+1);
	}
}

void solution()
{
	recursive_make(1, 0);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while(1)
	{
		cin >> k;
		if(!k)
			return 0;
		for(int i = 1; i <= k; i ++)
			cin >> ar[i];
		solution();
		cout << "\n";
	}
}