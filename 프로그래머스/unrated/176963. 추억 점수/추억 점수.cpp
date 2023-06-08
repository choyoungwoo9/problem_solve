#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> answer;
map<string, int> name_mp;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    
    for(int i = 0; i < name.size(); i++)
    {
        //name_map[may] = 5;
        name_mp[name[i]] = yearning[i];
    }
    
    for(int i = 0; i < photo.size(); i ++)
    {
        answer.push_back(0);
        for(int j = 0; j < photo[i].size(); j ++)
        {
            string tmp = photo[i][j];
            answer[i] += name_mp[tmp];
        }
        
    }
    
    return answer;
}