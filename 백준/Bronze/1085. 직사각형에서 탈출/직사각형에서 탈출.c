#include <stdio.h>

int x, y, w, h;

int min(int a, int b)
{
	if(a < b)
		return a;
	return b;
}

int main()
{
	scanf("%d %d %d %d", &x, &y, &w, &h);
	printf("%d", min(min(x, y), min(w - x, h - y)));
}