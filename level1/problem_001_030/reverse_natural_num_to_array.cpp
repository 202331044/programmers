#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(long long n) {
//     string str = to_string(n);
//     reverse(str.begin(), str.end());
    
//     vector<int> answer;
    
//     for(char& ch: str)
//         answer.push_back(ch - '0');
    
    vector<int> answer;
    
    while(n)
    {
        answer.push_back(n % 10);
        n /= 10;
    }
    
    return answer;
}
