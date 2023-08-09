#include <iostream>

using namespace std;

int main()
{
	int H, W;
	cin >> H >> W;
	if(H == 1)
	{
		cout << 1 << endl;
	}
	else if(H == 2)
	{
		if(W < 3)
			cout << 1 << endl;
		else if(W < 5)
			cout << 2 << endl;
		else if(W < 7)
			cout << 3 << endl;
		else
			cout << 4 << endl;
	}
	else
	{
		if(W == 1)
			cout << 1 << endl;
		else if(W == 2)
			cout << 2 << endl;
		else if(W == 3)
			cout << 3 << endl;
		else if(W < 7)
			cout << 4 << endl;
		else
			cout << W-2 << endl;
	}
}