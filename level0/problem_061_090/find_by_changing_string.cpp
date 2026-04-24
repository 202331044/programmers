#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat) {
    for(char& ch: pat)
    {
        if(ch == 'A') ch = 'B';
        else ch = 'A';
    }
    
    int idx = myString.find(pat);
    
    if(idx == string::npos) return 0;
    return 1;
}
