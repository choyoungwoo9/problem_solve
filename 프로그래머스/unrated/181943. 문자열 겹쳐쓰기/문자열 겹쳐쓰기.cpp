#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string overwrite_string, int s) {
    string answer = "";
    
    if(overwrite_string.size() >= s+my_string.size())
        return my_string.substr(0, s)+overwrite_string;
    else
        return my_string.substr(0, s)+overwrite_string+my_string.substr(s+overwrite_string.size(), my_string.size()-s+overwrite_string.size());
}