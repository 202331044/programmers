#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string a, string b) {
    string answer = "";
    bool carry = false;    
    int maxLen = max(a.size(), b.size());
    
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    
    for(int i = 0; i < maxLen; ++i)
    {
        int num1 = 0, num2 = 0;
        
        if(i < a.size()) num1 = (a[i] - '0');
        if(i < b.size()) num2 = (b[i] - '0');
        
        int sum = num1 + num2;
        
        if(carry) sum++;
        
        if(sum > 9) carry = true;
        else carry = false;
        
        answer += static_cast<char>((sum % 10) + '0') ;
    }
    
    if(carry) answer += '1';
    
    reverse(answer.begin(), answer.end());
    return answer;

}
