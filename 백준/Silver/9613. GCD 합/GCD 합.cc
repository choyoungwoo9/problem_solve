#include <vector>
#include <iostream>

using namespace std;

int getGCD(int a, int b)
{
	if(!a || !b)
		return 0;
	vector<int> vt;
	vt.push_back(1);
	int start = 2;
	while(1){
		if(start > a)
			break;
		if(a % start == 0){
			vt.push_back(start);
			a = a / start;
		}
		else{
			start ++;
		}
	}

	int ans = 1;
	for(auto i = vt.begin(); i != vt.end(); i++){
		if(b % *i == 0)
		{
			b = b / *i;
			ans *= *i;
		}
	}
	return ans;
}

void makeAnswer(vector<int> &vt)
{
	long long answer = 0;
	for(int i = 0; i < vt.size(); i++){
		for(int j = i+1; j < vt.size(); j++)
		{
			answer += getGCD(vt[i], vt[j]);
		}
	}
	cout << answer << "\n";
}

int main(){
	int T;
	cin >> T;
	for(int i = 0; i < T; i++)	
	{
		int N;
		cin >> N;
		vector<int> vt;
		for(int j = 0; j < N; j++)
		{
			int num;
			cin >> num;
			vt.push_back(num);
		}
		makeAnswer(vt);
	}
}