#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    int size = s.size();
    
    if(size% 2 != 0) return s.substr(size/2, 1);
    
    return s.substr(size/2 - 1, 2);
}
