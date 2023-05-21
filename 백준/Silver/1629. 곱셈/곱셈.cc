#include <iostream>

using namespace std;

int A, B, C;

int recursive_find(int count)
{
	if(count == 1)
		return A % C;
	unsigned long long find = recursive_find(count / 2);
	if(count % 2 == 0)
	{
		return (find * find) % C;
	}
	else
	{
		find = (find * find) % C;
		return (find * A) % C;
	}
}

int main()
{
	cin >> A >> B >> C;

	cout << recursive_find(B) << endl;
	
}