#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> count;
    
    for(const string& name: completion)
        count[name]++;
    
    for(string& p: participant)
    {
        if(count[p] == 0) return p;
        count[p]--;
    }
    
    return "";
}
