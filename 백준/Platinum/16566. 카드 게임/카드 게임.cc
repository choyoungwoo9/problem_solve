#include <iostream>
#include <algorithm>
using namespace std;

int N, M, K;

int input[4000001];
//카드가 가리키는 팀의 포인터
int cardPointer[4000001];

//포인터의 팀 표시
int pointerTeam[4000001];

//팀이 가리키는 카드 표시
int teamPointCard[4000001];

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M >> K;
	for(int i = 0; i < M; i ++)
		cin >> input[i];
	sort(input, input+M);
	int beforeNum = 1;
	//팀의 포인터 표시
	for(int i = 0; i < M; i ++)
	{
		//뽑은 카드
		int curNum = input[i];
		//이전의 카드들이 가리키는 포인터를 하나로 함
		for(int j = beforeNum; j < curNum; j++)
			cardPointer[j] = curNum;
		//포인터의 팀 표시
		pointerTeam[curNum] = curNum;
		//이전팀이 가리키는 카드를 현재 뽑은 카드로 정함
		teamPointCard[curNum] = curNum;
		beforeNum = curNum;
	}

	for(int i = 0; i < K; i ++)
	{
		int curCard;
		cin >> curCard;
		int pointer = cardPointer[curCard];
		int team = pointerTeam[pointer];
		int myCard = teamPointCard[team];
		cout << myCard << "\n";
		//현재팀이 가리키는 카드 변경
		int nextMyCard = teamPointCard[pointerTeam[cardPointer[myCard]]];
		teamPointCard[team] = nextMyCard;
		//팀 병합
		pointerTeam[cardPointer[myCard]] = team;
	}
}