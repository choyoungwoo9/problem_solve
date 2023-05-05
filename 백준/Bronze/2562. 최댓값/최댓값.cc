#include <iostream>

int main()
{
	int m_max = 0;
	int index = 0;
	for(int i = 0; i < 9; i ++)
	{
		int num;
		std::cin >> num;
		if(num > m_max)
		{
			m_max = num;
			index = i+1;
		}	
	}
	std::cout << m_max << std::endl;
	std::cout << index;
}