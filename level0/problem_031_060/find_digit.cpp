#include <string>
#include <vector>

using namespace std;

int solution(int num, int k) {
    string str = to_string(num);
    //char ch = k + '0';
    
    // for(int i = 0; i < str.size(); ++i)
    //     if(str[i] == ch) return i + 1;
    
    int idx = str.find(k + '0');
    
    return idx == string::npos ? -1 : idx + 1;
}
