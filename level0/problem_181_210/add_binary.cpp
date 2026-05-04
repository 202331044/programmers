#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string bin1, string bin2) {
    string answer = "";
    int carry = 0;
    //bool carry = false;
    
    reverse(bin1.begin(), bin1.end());
    reverse(bin2.begin(), bin2.end());
    
    int maxLen = bin1.size() > bin2.size() ? bin1.size() : bin2.size();
    
    for(int i = 0; i < maxLen; ++i)
    {
        int num1 = 0, num2 = 0;
        
        if(i < bin1.size()) num1 = bin1[i] - '0';
        if(i < bin2.size()) num2 = bin2[i] - '0';
        
        int sum = num1 + num2 + carry;
        
        answer += sum % 2 + '0';
        carry = sum / 2;
        
        //if(carry) sum++;
        
        //if(sum >= 2) carry = true;
        //else carry = false;
        
        //answer += static_cast<char>((sum % 2) + '0');
    }
    
    if(carry) answer += '1';
    
    reverse(answer.begin(), answer.end());
    
    return answer;
}
