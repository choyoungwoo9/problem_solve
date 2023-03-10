#include <iostream>
#include <algorithm>
using namespace std;

typedef struct value
{
	int num;
	int max;
}	value;

value v_ar[250 * 501 + 1];
int v_head = 1;

int main()
{
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++)
	{
		for(int j = 1; j <= i; j ++)
		{
			int num;
			cin >> num;
			v_ar[v_head].max = num;
			if(j == 1 && j == i)
			{
				v_ar[v_head].max = num;
			}
			else if(j == 1)
			{
				v_ar[v_head].max += v_ar[v_head-i+1].max;
			}
			else if(j == i)
			{
				v_ar[v_head].max += v_ar[v_head-i].max;
			}
			else
			{
				v_ar[v_head].max += max(v_ar[v_head-i+1].max, v_ar[v_head-i].max);
			}
			//printf("%d\n", v_ar[v_head].max);
			v_head ++;
		}
		if(i == n)
		{
			int max = 0;
			for(int j = 0; j < n; j ++)
			{
				if(max < v_ar[--v_head].max)
					max = v_ar[v_head].max;
			}
			cout << max << endl;
		}
	}

}