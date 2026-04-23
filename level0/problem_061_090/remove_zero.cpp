#include <string>
#include <vector>

using namespace std;

string solution(string n_str) {
    // for(int i = 0; i < n_str.size(); ++i)
    //     if(n_str[i] != '0') return n_str.substr(i);
    
    int idx = n_str.find_first_not_of('0');
    
    if(idx == string::npos) return n_str;
    return n_str.substr(idx);
}
