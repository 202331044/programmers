#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int solution(string s)
{
//     int maxLen = 1;
    
//     for(int left = 0; left < s.size(); ++left)
//     {
//         for(int len = maxLen + 1; len <= s.size() - left; ++len)
//         {
//             bool isValid = true;
//             string str = s.substr(left, len);
            
//             for(int i = 0; i < len / 2; ++i)
//             {
//                 if(str[i] != str[len - i - 1])
//                 {
//                     isValid = false;
//                     break;
//                 }
//             }
            
//             if(isValid)
//                 maxLen = len;
//         }
//     }

//     return maxLen;
    
    int maxLen = 0;
    
    for(int i = 0; i < s.size(); ++i)
    {
        for(int odd = 0; odd <= 1; ++odd)
        {
            int left = i;
            int right = i + odd;
            
            while(left >= 0 && right < s.size() && s[left] == s[right])
            {
                maxLen = max(maxLen, right - left + 1);
                left--;
                right++;
            }
        }
    }
    
    return maxLen;
}
