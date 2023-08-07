#include <iostream>
#include <string>
using namespace std;

string strStart = "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.";
string str1 = "\"재귀함수가 뭔가요?\"";
string str2 = "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.";
string str3 = "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.";
string str4 = "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"";

string strAns = "\"재귀함수는 자기 자신을 호출하는 함수라네\"";
string strAns2 = "라고 답변하였지.";
string dash = "____";

int num;

void printDashAndStr(int cnt, string &str){
	for(int i = 0; i < cnt; i++){
		cout << dash;
	}
	cout << str << "\n";
}

void recursivePrint(int depth){
	printDashAndStr(depth-1, str1);
	if(depth == num+1)
	{
		printDashAndStr(depth-1, strAns);
		printDashAndStr(depth-1, strAns2);
		return ;
	}
	printDashAndStr(depth-1, str2);
	printDashAndStr(depth-1, str3);
	printDashAndStr(depth-1, str4);
	recursivePrint(depth+1);
	printDashAndStr(depth-1, strAns2);
}

int main(){
	cin >> num;
	printDashAndStr(0, strStart);
	recursivePrint(1);
}