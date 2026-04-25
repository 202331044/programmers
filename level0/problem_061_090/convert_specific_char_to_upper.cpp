#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <iostream>

using namespace std;

string solution(string my_string, string alp) {
    char a = alp[0];

    // for(char& ch: my_string)
    //     if(ch == a) ch = toupper(ch);
    
    transform(my_string.begin(), my_string.end(), my_string.begin(),
             [a](char ch)
              {
                  if(ch == a) return static_cast<char>(toupper(ch));
                  return ch;
              });
    
    return my_string;
}
