#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

string solution(string myString) {
    transform(myString.begin(), myString.end(), myString.begin(), [](char ch)
               {
                   return toupper(ch);
               });
    
    return myString;
}
