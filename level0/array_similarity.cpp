#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<string> s1, vector<string> s2) {
    int answer = 0;
    
    // for(const string& str1: s1)
    //     for(const string& str2: s2)
    //         if(str1 == str2) answer++;
    
    unordered_set<string> s(s1.begin(), s1.end());
    
    for(const string& str: s2)
        if(s.count(str) != 0) answer++;
    
    return answer;
}
