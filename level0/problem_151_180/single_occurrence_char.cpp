#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(string s) {
    string answer = "";
    map<char, int> m;
    
    for(char ch: s)
        m[ch]++;

    for(auto [ch, cnt]: m)
        if(cnt == 1) answer += ch;
    
    return answer;
}
