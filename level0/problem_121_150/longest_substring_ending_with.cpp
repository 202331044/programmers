#include <string>
#include <vector>

using namespace std;

string solution(string myString, string pat) {
    string answer;
    int size = pat.size();
    
    // for(int i = 0; i < myString.size(); ++i)
    // {    
    //     if(myString.substr(i, size) == pat)
    //     {
    //         string str = myString.substr(0, i + size);
    //         answer = answer.size() > str.size() ? answer : str;
    //     }
    // }
    
    // for(int i = myString.size() - pat.size(); i >= 0; --i)
    // {
    //     if(myString.substr(i, size) == pat)
    //         return myString.substr(0, i + size);
    // }
    
    int idx = myString.rfind(pat);
    return myString.substr(0, idx + size);
}
