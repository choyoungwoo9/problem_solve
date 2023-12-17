#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	while(1)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if(a == 0 && b == 0 && c == 0)
			break;
		int maxNum = max(max(a, b), c);
		if(maxNum >= a+b+c-maxNum )
			cout << "Invalid\n";
		else if(a == b && b == c)
			cout << "Equilateral\n";
		else if(a != b && b != c && a != c)
			cout << "Scalene\n";
		else
			cout << "Isosceles\n";
	}
}